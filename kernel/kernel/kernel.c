#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>

//Functions
void kernel_init(void)
{
	term_init();
	term_print_string("HELLO WORLD");
}
