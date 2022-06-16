#include "shell.h"
/**
 * built_in - checks for built in command and execute separately
 * @string: char pointer as argu
 * Return: 0 if success, 1 if not
*/
int built_in(char *string)
{
	if (strncmp(string, "exit", 4) == 0)
	exit(0);
return (0);
}
