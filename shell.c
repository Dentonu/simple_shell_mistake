#include "shell.h"

int main(void)
{
	char *_lineptr = NULL, *tok, *line_ptr_copy;
	size_t n = 0;
	ssize_t return_getline;
       char prompt[] = "$ ";
       int j, i, status;
       char **array;
      /* pid_t child;*/

	while (1)
	{
		printf("%s ", prompt);
		return_getline = getline(&_lineptr, &n, stdin);
		if (return_getline == -1)
			break;
		if (return_getline == 1)
			continue;
		line_ptr_copy = strdup(_lineptr);

		tok = strtok(_lineptr, " ");
		j = 0;

		while (tok != NULL)
		{
			j++;
			tok = strtok(NULL, " ");
		}

		array = malloc(sizeof(char*) * j + 1);
		if (array == NULL)
		{
			perror("memory allocation error");
			exit(0);
		}

		
		tok = strtok(line_ptr_copy, " ");
		for (i = 0; tok != NULL; i++)
		{
			array[i] = malloc(sizeof(char) * strlen(tok));
			if (array[i] == NULL)
			{
				perror("memory allocation error");
				exit(0);
			}
			strcpy(array[i], tok);
			tok = strtok(NULL, " ");
		}
		array[i] = NULL;
		
		if (array)

			return (0);
}
