#ifndef SHELL_H
#define SHELL_H
#define SIZE 256
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int process(char **cmd);
#endif
