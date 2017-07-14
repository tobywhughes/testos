#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>

//Functions
void kernel_init(void)
{
	term_init();
	for(int i = 0; i < 100; i++)
	{
		term_print_string("0123456789");
	}
}
