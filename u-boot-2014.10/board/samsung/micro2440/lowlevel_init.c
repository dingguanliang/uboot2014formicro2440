#include "types.h"
#include "register.h"
#include "io.h"
#include "wdt_off.h"
#include "int_off.h"
#include "clock_init.h"
#include "mem_init.h"

void lowlevel_init(void)
{
	WT_OFF();
	INT_OFF();
	CLK_INIT();
	MEM_INIT();
}
