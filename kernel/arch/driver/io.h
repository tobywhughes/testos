#ifndef _IO_H
#define _IO_H

#include <stddef.h>

static inline uint8_t inb(uint16_t port)
{
	uint8_t val;
	asm volatile("inb %1, %0" : "=a"(val) : "Nd"(port));
	return val;
}

#endif
