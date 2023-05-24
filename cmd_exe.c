#include "shell.h"

void cmd_exe(char **array)
{
	char *cmd;
       
	cmd = array[0];

	if (array)
	{
		if (execve(cmd, array, NULL) == -1)
		{
			perror("Error...");

		}
	}

}
