#include <stddef.h>
#include <stdint.h>
#include <driver/kbdrive.h>
#include "io.h"

static char last_c = 0;

char getScancode()
{
	char c = 0;
	while(1)
	{
		if(inb(0x60) != c)
		{
			c=inb(0x60);
			if(c > 0 && c != last_c)
			{
				last_c = c;
				return c;
			}
		}
	}
}

char parse(char code)
{
	switch(code){
		case 0x01:
			return '\0';
		case 0x02:
			return '1';
		case 0x03:
			return '2';
		case 0x04:
			return '3';
		case 0x05:
			return '4';
		case 0x06:
			return '5';
		case 0x07:
			return '6';
		case 0x08:
			return '7';
		case 0x09:
			return '8';
		case 0x0A:
			return '9';
		case 0x0B:
			return '0';
		case 0x0C:
			return '-';
		case 0x0D:
			return '=';
		case 0x0E:
			return '\0';
		case 0x0F:
			return '\0';	
		case 0x10:
			return 'Q';
		default:
			return '~';
			break;
	}
}

char getChar()
{
	return parse(getScancode());
}
