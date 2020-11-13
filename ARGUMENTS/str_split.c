#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int print_string(char *str)
{
	return (write(1, str, strlen(str)));
}
char **str_split(char *str)
{
	char **foundWord = 0;
	char **holder;
	int index;


	*foundWord = strtok(str, " ");
	if(!foundWord)
	{
		holder = foundWord;
		return(holder);
	}

	for (index = 0; *foundWord[index]; index++ )
	{
		foundWord = &foundWord[index +1];
		*foundWord = strtok(NULL, " ");
	}
	return(foundWord);
}
int main (void)
{
	char *testStr = "test to see if string splits";

	str_split(testStr);
	return (0);
}
