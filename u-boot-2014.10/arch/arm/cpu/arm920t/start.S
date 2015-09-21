#include "core_config.h"

.globl	reset	// define globle enter address.
reset:
	// change to SVC mode.
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr, r0

	mov	r0, #0
	mcr	p15, 0, r0, c7, c7, 0	// flush v3/v4 cache.
	mcr	p15, 0, r0, c8, c7, 0	// flush v4 TLB.

	// disable MMU stuff and caches.
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002300	// clear bits 13, 9:8 (--V- --RS).
	bic	r0, r0, #0x00000087	// clear bits 7, 2:0 (B--- -CAM).
	orr	r0, r0, #0x00000002	// set bit 2 (A) Align.
	orr	r0, r0, #0x00001000	// set bit 12 (I) I-Cache.
	mcr	p15, 0, r0, c1, c0, 0

	// check boot mode.
	ldr r0, =0x48000000
	ldr r0, [r0]
    ands r0, r0, #0x06
	bne nom_init

nand_init:
	ldr sp, =0x00001000
	b	init

nom_init:
	ldr sp, =0x40001000

init:
	bl lowlevel_init	// jump to lowlevel initial.

	// check boot mode.
	ldr r0, =0x48000000
	ldr r0, [r0]
    ands r0, r0, #0x06
	bne nom

	// nand boot.
nand:
	ldr sp, =(__image_copy_start - CONFIG_SYS_MALLOC_SIZE - CONFIG_SYS_GBL_DATA_SIZE)
	bl	nand_boot
	b	stack_setup

	// nor or mem boot.
nom:			
	adr	r0, reset
	ldr	r1, =__image_copy_start	
	cmp	r0, r1			
	beq	stack_setup

	// code relocate.
	ldr	r2, =__image_copy_start
	ldr	r3, =__image_copy_end
	sub	r2, r3, r2		
	add	r2, r0, r2		

0:
	ldmia r0!, {r3-r10}		
	stmia r1!, {r3-r10}	
	cmp	r0, r2			
	ble	0b

	// mem init.
stack_setup:
	ldr	r0, =__image_copy_start	
	sub	r0, r0, #CONFIG_SYS_MALLOC_SIZE	
	sub	r0, r0, #CONFIG_SYS_GBL_DATA_SIZE

	// clear bss.
	ldr	r0, =__bss_start		
	ldr	r1, =__bss_end		
	mov	r2, #0x0	

1:
	str	r2, [r0]	
	add	r0, r0, #4
	cmp	r0, r1
	ble	1b

	ldr	pc, =_main	// jump to 2nd.

.globl c_runtime_cpu_setup
c_runtime_cpu_setup:
	mov pc, lr
