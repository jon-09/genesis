#include "header.h"

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	do {
		printf(">>> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
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

char **lsh_split_line(char *line)
{
	int bufsize = 64, post = 0;
	char *token;
	char **tokens = malloc(sizeof(char) * (bufsize + 1));

	if (tokens == NULL)
		exit(EXIT_FAILURE);

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[post] = token;
		token = strtok(NULL, " ");
		post++;
	}
	return (tokens);
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
