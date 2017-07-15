#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>
#include <driver/kbdrive.h>
//Functions
void kernel_init(void)
{
	term_init();
	char code = getScancode();
	term_print_string(code);
	for(int i = 0; i < 100; i++)
	{
		term_print_string("0123456789");
	}
}
