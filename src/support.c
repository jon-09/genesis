#include "header.h"

int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int state;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args) == -1)
			perror("Nothing");

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Nothing");

	else
	{
		do {
			wpid = waitpid(pid, &state, WUNTRACED);
		}while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	return (1);
}

int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);

	}
	return (lsh_launch(args));
}
			
