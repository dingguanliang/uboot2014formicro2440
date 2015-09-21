#include "types.h"
#include "register.h"
#include "io.h"

#define MAIN_FIELD_SIZE	2048

// nand flash chip (K9F2G08U0B) command.
#define READ_1ST				0x00
#define READ_2ND				0x30
#define RESET					0xff

// nand flash chip (K9F2G08U0B) status.
#define BUSY	0
#define READY	1

#define NAND_CHIP_SELECT()		(WRITED(NFCONT, READD(NFCONT) & ~BIT1))
#define NAND_CHIP_UNSELECT()	(WRITED(NFCONT, READD(NFCONT) | BIT1))
#define NAND_RNB_CHECK()		((READD(NFSTAT) & BIT0)?READY:BUSY)

#define NAND_RESET() do \
{ \
	WRITED(NFCMMD, RESET); \
	while(!NAND_RNB_CHECK()); \
}while(0)

inline void nand_read_1st(uint32_t addr, uint8_t *buf, uint16_t size)
{
	NAND_CHIP_SELECT();
	while(!NAND_RNB_CHECK());
	WRITED(NFCMMD, READ_1ST);
	WRITED(NFADDR, (addr >> 0)	& 0xff);
	WRITED(NFADDR, (addr >> 8)	& 0x0f);
	WRITED(NFADDR, (addr >> 12)	& 0xff);
	WRITED(NFADDR, (addr >> 20) & 0xff);
	WRITED(NFADDR, (addr >> 28) & 0x01);
	WRITED(NFCMMD, READ_2ND);
	while(!NAND_RNB_CHECK());
	while(size--)
		*buf++ = READB(NFDATA);
	NAND_CHIP_UNSELECT();
}

extern uint8_t __image_copy_start, __image_copy_end;

void nand_boot(void)
{
	uint8_t buf;
	uint32_t cur_blo_addr = 1;
	uint32_t nand_addr = 0;
	int32_t fsize = &__image_copy_end - &__image_copy_start;
	uint8_t *mem_addr = (uint8_t *)&__image_copy_start;

	// nand flash contraller initial.
	WRITED(NFCONF, READD(NFCONF) | (2 << 12) | (1 << 8) | (1 << 4));
	WRITED(NFCONT, READD(NFCONT) | (1 << 6) | (1 << 5) | (1 << 1) | (1 << 0));

	NAND_CHIP_SELECT();
	NAND_RESET();
	NAND_CHIP_UNSELECT();

	while(fsize > 0)
	{
		if(cur_blo_addr != (nand_addr >> 18))
		{
			cur_blo_addr = nand_addr >> 18;
			nand_read_1st((nand_addr + 2048), &buf, 1);
		}
		if(0xff == buf)
		{
			nand_read_1st(nand_addr, mem_addr, MAIN_FIELD_SIZE);
			mem_addr += MAIN_FIELD_SIZE; 
			fsize -= MAIN_FIELD_SIZE;
			nand_addr += 1 << 12;	// jump to next page.
		}
		else	
			nand_addr = (nand_addr & ~(0x3f << 12)) + (1 << 18); // jump to next block.
	};
}
