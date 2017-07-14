#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>

//Functions
void kernel_init(void)
{
	term_init();
	term_print_char('H');
	term_print_char('E');
	term_print_char('L');
	term_print_char('L');
	term_print_char('O');
	term_print_char(' ');
	term_print_char('O');
	term_print_char('S');
}
