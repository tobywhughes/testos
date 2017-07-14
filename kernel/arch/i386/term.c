#include <stddef.h>
#include <kernel/term.h>

size_t strln(const char*);

//Global Vars
static volatile char *vram;
static char term_color;

size_t strlen(const char* str)
{
	size_t len = 0;
	while(*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}
//Functions
void term_init(void)
{
	vram = (volatile char*) 0xB8000;
	term_color = 0x07;
}

void term_print_char(char c)
{
	*vram++ = c;
	*vram++ = term_color;	
}

void term_print_string(const char* str)
{
	for(size_t i = 0; i < strlen(str); i++)
	{
		term_print_char(str[i]);
	}
}


