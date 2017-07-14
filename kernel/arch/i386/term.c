#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/term.h>
#include <string.h>

#define MAX_W 80

//Global Vars
static volatile char *vram;
static uint8_t term_color;
static uint8_t col;
static uint8_t row;

//Functions
void term_init(void)
{
	vram = (volatile char*) 0xB8000;
	col = 0;
	row = 0;
	uint8_t color_fground = 0x7;
	uint8_t color_bground = 0x0;
	term_color = color_bground << 4 | color_fground;
}

uint16_t get_loc(void)
{
	return ((row * 80) + col) * 2;
}

void update_loc(void)
{
	if (col == MAX_W)
	{
		col = 0;
		row++;
	}
	else 
	{
		col++;
	}
}

void term_print_char(char c)
{
	uint16_t loc = get_loc();
	vram[loc] = c;
	vram[loc + 1] = (char) term_color;
	update_loc();	
}

bool parse_char(char c)
{
	if(c == '\n'){
		row++;
		col = 0;
		return false;
	}
	else {
		return true;
	}
}

void term_print_string(const char* str)
{
	for(size_t i = 0; i < strlen(str); i++)
	{
		if(parse_char(str[i]))
		{
			term_print_char(str[i]);
		}
	}
}


