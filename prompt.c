#include "shell.h"
#include <sys/wait.h>

void prompt(char **av, char **env)
{
	char *string = NULL;
	int i, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};
	pid_t pd_pid;

	while(1)
	{
		printf("$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (num_char == 1)
		{
		printf("$ ");
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}
		argv[0] = string;/* The command that the user types in,  put it as the the first argument to the array of string (char *argv[] = {NULL, NULL}). So the null will be changed to whatever command the user types in*/
		pd_pid = fork();
		if (pd_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		
		}
		if (pd_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)/* if after it has executed this function and it checks if what was returned is -1, it means it failed. I will then display an error message*/
			printf("%s: No such file or directory\n", av[0]);	
		
		}
		else
			wait(&status); /* wait for the pd process to run it's own program'*/
	}

}
