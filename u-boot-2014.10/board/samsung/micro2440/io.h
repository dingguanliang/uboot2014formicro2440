#ifndef __IO_H__
#define __IO_H__

// read data from register.
#define READB(addr)			(*((volatile uint8_t *)(addr)))
#define READW(addr)			(*((volatile uint16_t *)(addr)))
#define READD(addr)			(*((volatile uint32_t *)(addr)))

// write data to register.
#define WRITEB(addr, data)	(*((volatile uint8_t *)(addr)) = (data))
#define WRITEW(addr, data)	(*((volatile uint16_t *)(addr)) = (data))
#define WRITED(addr, data)	(*((volatile uint32_t *)(addr)) = (data))

#endif
