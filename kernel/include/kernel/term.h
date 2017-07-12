#ifndef _KERNEL_TERM_H
#define _KERNEL_TERM_H

#include <stddef.h>

void term_init();
void term_write_char(char c);
void term_write_string(const char* data);

#endif
