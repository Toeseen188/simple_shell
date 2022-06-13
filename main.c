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
	if (argc >= 2)
	{
	if (execve(argv[1], argv, NULL) == -1)
	{
	perror("Error");
	exit(-1);
	}
	return (0);
	}
	string = malloc(size);
	while (1)
	{
	printf("#cisfun$ ");
	if (getline(&string, &size, stdin) == EOF)
	exit(0);
	if (string[strlen(string) - 1] == '\n')
	string[strlen(string) - 1] = '\0';
	if (strncmp(string, "exit", 4) == 0)
	break;
	token =	strtok(string, "\n");
	while (token)
	token = strtok(NULL, "\n");
	process(&string);
	}
	free(string);
	return (0);
}
