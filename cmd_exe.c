#include "shell.h"

void cmd_exe(char **array)
{
	char *cmd = NULL;
       
	if (array)
	{	
		cmd = array[0];
		if (execve(cmd, array, NULL) == -1)
		{
			printf("%s Error...", array[0]);

		}
	}

}
