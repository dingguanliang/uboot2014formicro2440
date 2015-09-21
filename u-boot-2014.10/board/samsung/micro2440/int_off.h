#define INT_OFF() do \
{ \
	WRITED(INTMSK, 0xffffffff); \
	WRITED(INTSUBMSK, 0xffffffff); \
}while(0)
