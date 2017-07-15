#include <stddef.h>
#include <stdint.h>
#include <driver/kbdrive.h>
#include "io.h"

char getScancode()
{
	char c = 0;
	while(1)
	{
		if(inb(0x60) != c)
		{
			c=inb(0x60);
			if(c > 0){
				return c;
			}
		}
	}
}

char getChar(){;}
