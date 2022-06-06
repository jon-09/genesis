#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 30
/**
 * main - entry
 *
 * Return: alwyas 0
 */
int main(void)
{
	int btes;
	size_t size = 12;
	char *str;

	printf("$ ");

	str = malloc(sizeof(char *) * size);
	btes = getline(&str, &size, stdin);
	if (btes == -1)
		return (-1);

	puts(str);
	return (0);

}
