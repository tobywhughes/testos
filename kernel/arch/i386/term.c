#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/term.h>
#include <driver/io.h>
#include <string.h>

#define MAX_W 80
#define MAX_CHAR 256

//Global Vars
static volatile char *vram;
static uint8_t term_color;
static uint8_t col;
static uint8_t row;
static char line_holder[MAX_CHAR];
static bool keyboard_on;

//Functions
void term_init(void)
{
	vram = (volatile char*) 0xB8000;
	col = 0;
	row = 0;
	uint8_t color_fground = 0x7;
	uint8_t color_bground = 0x0;
	term_color = color_bground << 4 | color_fground;
	keyboard_on = true;
	term_print_char('>');
}

uint16_t get_loc(void)
{
	return ((row * 80) + col) * 2;
}

void update_loc(void)
{
	if (col == MAX_W - 1)
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

void log_print(const char * str)
{
	while (*str != '\0')
	{
		outb(COM1, *str);
		str++;
	}
}

void exec_line(const char * str)
{
	keyboard_on = false;
	log_print(str);
	log_print("\n");
//	term_print_string(str);
//	term_print_string("\n");
	if(strcmp(str, "TEST") == 0)
	{
		;	
	}
	else 
	{
		keyboard_on = true;
	}
}

bool get_keyboard_state()
{
	return keyboard_on;
}

void set_keyboard_state(bool state)
{
	keyboard_on = state;
}

bool parse_char(char c)
{
	switch(c)
	{
		case '\n':
			row++;
			col = 0;
			if(keyboard_on)
			{
				keyboard_on = false;
				line_holder[strlen(line_holder) - 1] = '\0';
				exec_line(line_holder);
				line_holder[0] = '\0';
				if(keyboard_on)
				{
					term_print_char('>');		
				}
			}
			return false;
		case (char) 0x08:
			if(col > 1){
				col--;
				term_print_char('\0');
				col--;
				line_holder[strlen(line_holder) - 2] = '\0';
			}
			return false;
		default:
			return true;
			break;
	}
	
}

void term_print_string(const char* str)
{
	if(keyboard_on){
		strcat(line_holder, str);
	}
	for(size_t i = 0; i < strlen(str); i++)
	{
		if(parse_char(str[i]))
		{
			term_print_char(str[i]);
		}
	}
}


