#include <string.h>

char * strcat(char * s1, const char * s2)
{
	char *s = s1;
	while (*s != '\0')
	{
		s++;
	}
	strcpy(s, s2);
	return s1;
}
