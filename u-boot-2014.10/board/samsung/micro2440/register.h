#ifndef __REGISTER_H__
#define __REGISTER_H__

/* define bit. */
#define BIT0		(0x01 << 0)
#define BIT1		(0x01 << 1)
#define BIT2		(0x01 << 2)
#define BIT3		(0x01 << 3)
#define BIT4		(0x01 << 4)
#define BIT5		(0x01 << 5)
#define BIT6		(0x01 << 6)
#define BIT7		(0x01 << 7)
#define BIT8		(0x01 << 8)
#define BIT9		(0x01 << 9)
#define BIT10		(0x01 << 10)
#define BIT11		(0x01 << 11)
#define BIT12		(0x01 << 12)
#define BIT13		(0x01 << 13)
#define BIT14		(0x01 << 14)
#define BIT15		(0x01 << 15)
#define BIT16		(0x01 << 16)
#define BIT17		(0x01 << 17)
#define BIT18		(0x01 << 18)
#define BIT19		(0x01 << 19)
#define BIT20		(0x01 << 20)
#define BIT21		(0x01 << 21)
#define BIT22		(0x01 << 22)
#define BIT23		(0x01 << 23)
#define BIT24		(0x01 << 24)
#define BIT25		(0x01 << 25)
#define BIT26		(0x01 << 26)
#define BIT27		(0x01 << 27)
#define BIT28		(0x01 << 28)
#define BIT29		(0x01 << 29)
#define BIT30		(0x01 << 30)
#define BIT31		(0x01 << 31)
#define BIT0_7		(0xff << 0)
#define BIT8_15		(0xff << 8)
#define BIT16_23	(0xff << 16)
#define BIT24_31	(0xff << 24)
#define BITALL		(0xffffffff << 0)

/* memory contorller (S3C2440) register address. */
#define MEM_BASE	0x48000000
#define BWSCON		(MEM_BASE + 0x00)
#define BANKCON6	(MEM_BASE + 0x1c)
#define REFRESH		(MEM_BASE + 0x24)
#define BANKSIZE	(MEM_BASE + 0x28)
#define MRSRB6		(MEM_BASE + 0x2c)

/* interrupt contorller (S3C2440) register address. */
#define INT_BASE	0x4a000000
#define SRCPND 		(INT_BASE + 0x00)
#define INTMOD		(INT_BASE + 0x04)
#define INTMSK		(INT_BASE + 0x08)
#define INTPND		(INT_BASE + 0x10)
#define INTOFFSET	(INT_BASE + 0x14)
#define SUBSRCPND 	(INT_BASE + 0x18)
#define INTSUBMSK	(INT_BASE + 0x1c)

/* dma contorller (S3C2440) register address. */
#define DMA0_BASE	0x4b000000
#define DMA1_BASE	0x4b000040
#define DMA2_BASE	0x4b000080
#define DMA3_BASE	0x4b0000c0

/* CLOCK (S3C2440) register address. */
#define CLK_BASE	0x4c000000
#define MPLLCON		(CLK_BASE + 0X04)
#define CLKDIVN		(CLK_BASE + 0X14)

/* nand flash contorller (S3C2440) register address. */
#define NAND_BASE	0x4e000000
#define NFCONF		(NAND_BASE + 0x00)
#define NFCONT		(NAND_BASE + 0x04)
#define NFCMMD		(NAND_BASE + 0x08)
#define NFADDR		(NAND_BASE + 0x0c)
#define NFDATA		(NAND_BASE + 0x10)
#define NFSTAT		(NAND_BASE + 0x20)

/* UART (S3C2440) register base address. */
#define UART0_BASE	0x50000000
#define UART1_BASE	0x50004000
#define UART2_BASE	0x50008000

#define UART0		UART0_BASE
#define UART1		UART1_BASE
#define UART2		UART2_BASE

/* timer contorller (S3C2440) register address. */
#define TCFG0		0x51000000
#define TCFG1		0x51000004
#define TCON		0x51000008

#define TIMER0_BASE	0x5100000c
#define TIMER1_BASE	0x51000018
#define TIMER2_BASE	0x51000024
#define TIMER3_BASE	0x51000030

/* watchdog timer contorller (S3C2440) register address. */
#define WT_BASE	0x53000000
#define WTCON	(WT_BASE + 0x00)
#define WTDAT	(WT_BASE + 0x04)
#define WTCNT	(WT_BASE + 0x08)

/* iic bus contorller (S3C2440) register address. */
#define IIC_BASE	0x54000000
#define IICCON 		(IIC_BASE + 0x00)
#define IICSTAT 	(IIC_BASE + 0x04)
#define IICADD 		(IIC_BASE + 0x08)
#define IICDS 		(IIC_BASE + 0x0c)
#define IICLC		(IIC_BASE + 0x10)

/* GPIO (S3C2440) register base address. */
#define GPA_BASE		0x56000000
#define GPB_BASE		0x56000010
#define GPC_BASE		0x56000020
#define GPD_BASE		0x56000030
#define GPE_BASE		0x56000040
#define GPF_BASE		0x56000050
#define GPG_BASE		0x56000060
#define GPH_BASE		0x56000070
#define GPJ_BASE		0x560000d0

#define EXTINT0 		0x56000088
#define EXTINT1 		0x5600008c
#define EXTINT2 		0x56000090
#define EINTMASK 		0x560000a4
#define EINTPEND 		0x560000a8

#define GPXCON_OFFSET	0x00
#define GPXDAT_OFFSET	0x04
#define GPXUP_OFFSET	0x08

#define GPA	GPA_BASE
#define GPB	GPB_BASE
#define GPC	GPC_BASE
#define GPD	GPD_BASE
#define GPE	GPE_BASE
#define GPF	GPF_BASE
#define GPG	GPG_BASE
#define GPH	GPH_BASE
#define GPJ	GPJ_BASE

/* rtc contorller (S3C2440) register base address. */
#define RTC_BASE	0x57000040

/* adc contorller (S3C2440) register base address. */
#define ADC_BASE	0x58000000

#define ADCCON		(ADC_BASE + 0x00)
#define ADCTSC		(ADC_BASE + 0x04)
#define ADCDLY		(ADC_BASE + 0x08)
#define ADCDAT0		(ADC_BASE + 0x0c)
#define ADCDAT1		(ADC_BASE + 0x10)
#define ADCUPDN		(ADC_BASE + 0x14)

#endif
