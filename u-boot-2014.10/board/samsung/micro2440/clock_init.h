#define CLK_INIT() do \
{ \
	WRITED(MPLLCON, (0x01 << 0) | (0x01 << 4) | (0x5c << 12)); \
	asm volatile("mrc p15, 0, r0, c1, c0, 0"); \
	asm volatile("orr r0, r0, #0xc0000000"); \
	asm volatile("mcr p15, 0, r0, c1, c0, 0"); \
	WRITED(CLKDIVN, (0x01 << 0) | (0x02 << 1)); \
}while(0)
