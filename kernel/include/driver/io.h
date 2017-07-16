#ifndef _IO_H
#define _IO_H

#include <stddef.h>

#define COM1 0x3F8

static inline uint8_t inb(uint16_t port)
{
	uint8_t val;
	asm volatile("inb %1, %0" : "=a"(val) : "Nd"(port));
	return val;
}

static inline void outb(uint16_t port, uint8_t val)
{
	asm volatile("outb  %0, %1" : : "a"(val), "Nd"(port));
}


#endif
