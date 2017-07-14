#ifndef _KERNEL_TERM_H
#define _KERNEL_TERM_H

#include <stddef.h>

void term_init(void);
void term_print_char(char);
void term_print_string(const char*);

#endif
