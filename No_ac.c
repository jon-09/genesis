#include <unistd.h>
#include <stdio.h>

/**
 *
 * main - entry
 *
 * Return: always 0
 *
 */
int main(__attribute__((unused))int argc, char **argv)
{
	unsigned int i = 0;

	for (; argv[i] != NULL; i++)
		puts(argv[i]);

	return (0);
}
