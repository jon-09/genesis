#include "header.h"

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	do {
		printf(">>> ");
		line = lsh_read_line();
/*		args = lsh_split_line(line);*/
/*		status = lsh_execute(args);*/

		free(line);
/*		free(args);*/
	}while (status);

	return EXIT_SUCCESS;
}

char *lsh_read_line(void)
{
	char *line = NULL;
	ssize_t reads = 0;
	size_t bufsize = 0;

	reads = getline(&line, &bufsize, stdin);
	if (reads == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO) != 0)
		{
			perror("\n");
			exit(EXIT_SUCCESS);
		}
	}
	return (line);
}
