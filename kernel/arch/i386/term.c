#include <stddef.h>
#include <kernel/term.h>

//Global Vars
static volatile char *vram;

//Functions
void term_init(void)
{
	vram = (volatile char*) 0xB8000;
}

void term_print_char(char c)
{
	*vram++ = c;
	*vram++ = 0x1C;	
}

void term_print_string(const char* str)
{
	;
}
