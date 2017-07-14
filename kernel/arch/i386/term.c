#include <stddef.h>
#include <stdint.h>
#include <kernel/term.h>
#include <string.h>


//Global Vars
static volatile char *vram;
static uint8_t term_color;

//Functions
void term_init(void)
{
	vram = (volatile char*) 0xB8000;
	uint8_t color_fground = 0x7;
	uint8_t color_bground = 0x0;
	term_color = color_bground << 4 | color_fground;
}

void term_print_char(char c)
{
	*vram++ = c;
	*vram++ = (char) term_color;	
}

void term_print_string(const char* str)
{
	for(size_t i = 0; i < strlen(str); i++)
	{
		term_print_char(str[i]);
	}
}


