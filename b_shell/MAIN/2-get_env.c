#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char **environ;
int _strncmp(char *s1, char *s2, size_t n)
{
	int index = 0;

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2 && index < n)
	{
		s1++;
		s2++;
		index++;

		if (*s1 == *s2)
			return (0);

		else
			return (*s1 - *s2);

	}
}
int _strlen(char *str)
{
	int count;

	for (count = 0; str[count]; count++);
	return (count);
}
char *_getenv(char *enVar)
{
	unsigned int index = 0;
	size_t len;


	len = strlen(enVar);
	while(environ)
	{
		if(_strncmp(enVar, environ[index], len) == 0)
			return(environ[index]);
		index++;
	}
	return (NULL);
}
int main(void)
{
	char *varry = "PATH";
	char *PH;

	PH = _getenv(varry);
	printf("%s\n", PH);
	return (0);
}
