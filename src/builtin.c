#include "header.h"

int lsh_ls(char **args)
{
	printf("printing ls");

	return (0);
}

int ls_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");

	else
	{
		if (chdir(args[1]) != 0)
			perror("Nothing\n");

	}
	return (1);
}

int lsh_help(char **args)
{
	int i;

	printf("Custom Terminal\n");
	printf("Type prog names and args, hit enter after\n");
	printf("built ins:\n");

	for (i =0; i < lsh_num_builtins(); i++)
		printf(" %s\n", builtin_str[1]);

	return (1);
}

int lsh_exit(char **args)
{
	return (0);
}
