#include "shell.h"
/**
 * main - main function that takes two arguments
 * @argc: parameter, arguments counts
 * @argv: parameter, arguments vector, i.e an array that stores
 * all arguments passed
 * Return: return 0, if success and 1 if otherwise
 */
int main(int argc, char *argv[])
{
	size_t size = SIZE;
	char *string;
	char *token;
	/* handles numbers of arguments*/
	if (argc >= 2)
	{
	if (execve(argv[1], argv, NULL) == -1)
	{
	perror("Error");
	exit(-1);
	}
	return (0);
	}
	/* allocate a memory space for the buffer- string*/
	string = malloc(size);
	while (1)
	{
	printf("#cisfun$ ");

	/* getline input from stdin and save in buffer */
	if (getline(&string, &size, stdin) == EOF)
		break;

	/* get rid of trailing spaces and newline by adding NULL */
	if (string[strlen(string) - 1] == '\n')
	string[strlen(string) - 1] = '\0';

	/* exit if "exit" is typed */
	if (strncmp(string, "exit", 4) == 0)
	break;
	/* get string token if seperated by space */
	token =	strtok(string, "\n");
	while (token)
	token = strtok(NULL, "\n");
	
	/* call process fun*/
	process(&string);
	}
	/* free memory */
	free(string);
	return (0);
}
