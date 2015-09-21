/* BWSCON */
#define DW8				(0x0)
#define DW16			(0x1)
#define DW32			(0x2)
#define WAIT			(0x1<<2)
#define UBLB			(0x1<<3)

#define B6_BWSCON		(DW32)

/* BANKCON */
#define B6_MT			0x3
#define B6_Trcd			0x1
#define B6_SCAN			0x1

/* REFRESH parameter */
#define REFEN			0x1
#define TREFMD			0x0
#define Trp				0x1
#define Trc				0x1
#define Tchr			0x2
#define REFCNT			1268

#define MEM_INIT() do \
{ \
	WRITED(BWSCON,					(B6_BWSCON<<24)); \
	WRITED(BANKCON6,  				((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))); \
	WRITED(REFRESH, 				((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)); \
	WRITED(BANKSIZE,  				0x32); \
	WRITED(MRSRB6, 					0x30); \
}while(0)
