#include <string.h>

char* strcpy(char *s1, const char *s2)
{
	char *dst = s1;
	const char  *src = s2;
	while((*dst++  = *src++) != '\0')
	{;}
	return s1;
}
