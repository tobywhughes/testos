#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>
#include <driver/kbdrive.h>
//Functions
void kernel_init(void)
{
	term_init();
	while(1)
	{
		char c =  getChar();
		term_print_char(c);
	}
	for(int i = 0; i < 100; i++)
	{
		term_print_string("0123456789");
	}
}
