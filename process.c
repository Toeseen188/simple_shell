#include "shell.h"
/**
* process - a function that create a child process from parent,
* return and wait if not return
* @cmd: a pointer to a char pointer as param
* Return: return 0 if success, and 1 if otherwise
*/

int process(char **cmd)
{
	pid_t child_pid;
	int status = 0;
	/*create a child process */
	child_pid = fork();
	/* handle errors */
	if (child_pid == -1)
	{
	perror("Error: ");
	return (1);
	}
	/* if a child is created? */
	else if (child_pid == 0)
	{
	if (execve(cmd[0], cmd, NULL) == -1)
	{
	perror("./shell");
	exit(-1);
	}
	}
	else
	/* wait for the child process to return */
	wait(&status);
	return (0);
}
