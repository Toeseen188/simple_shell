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
	char *store;
	char *envp[] = { NULL };

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
	
	/* execute if first param is a path or valid */
	execve(cmd[0], cmd, envp);

	/* else, create a buffer and do the following */
	store = malloc(SIZE);

	/* save /bin/ls into store */
	strcpy(store, "/bin/");

	/* concatenate cmd with "/bin/" */
	strcat(store, *cmd);

	/* execute store and give error if -1 is returned */
	if (execve(store, &store, envp) == -1)
	{
	perror("./shell");
	exit(-1);
	}
	free(store);
	}
	else
	/* wait for the child process to return */
	wait(&status);
	return (0);
}
