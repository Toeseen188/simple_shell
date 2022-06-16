#include "shell.h"
/**
 * _getline - gets the string input and save in buffer
 * @string: param, char pointers
 * Return: returns 0 if success
*/
int _getline(char *string)
{
	/* gets string input into buffer*/
	if (fgets(string, SIZE, stdin) == NULL && ferror(stdin))
	perror("fget error");
	/* EOF */
	if (feof(stdin))
	{
	printf("\n");
	fflush(stdout);
	exit(0);
	}
return (0);
}
