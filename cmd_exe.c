#include "shell.h"

void cmd_exe(char **array)
{
	char*cmd;
       
	cmd = array[0];

	if (array)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perro("Error...");

		}
	}

}
