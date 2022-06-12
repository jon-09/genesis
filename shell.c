#include "header.h"

int main(void)
{
	char *liner, *line;
	ssize_t bufsize = 0;
	int zil, rd, i;

	printf("Custom Terminal\n");
	while (1)
	{
		printf(">$ ");
		/*fflush(stdin);*/
		if (getline(&line, &bufsize, stdin) == -1)
		{
			if(fflush(stdin))
			{
				if (i == 0)
				{
					i = read(0, line, 1);
					liner = line;
				}
				if (--i < 0)
				{
					perror("END OF LINE");
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("custom_shell: getline\n");
					exit(EXIT_FAILURE);
				}
			
			}
		}
	
	}
}

