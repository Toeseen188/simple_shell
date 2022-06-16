#include "shell.h"
/**
 * _getline - gets the string input and save in buffer
 * @string: param, char pointers
 * Return: returns 0 if success
*/
int _getline(char *string)
{
	size_t size = SIZE;

	if (getline(&string, &size, stdin) == EOF)
	{
	printf("\n");
	exit(0);
	}
	/* get rid of trailing newlines*/
	if (string[strlen(string) - 1] == '\n')
	string[strlen(string) - 1] = '\0';
	/* exit if 'exit" is typed */
	if (strncmp(string, "exit", 4) == 0)
	exit(0);
return (0);
}
