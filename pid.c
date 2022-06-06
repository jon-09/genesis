#include <unistd.h>
#include <stdio.h>
/**
 * main - entry
 *
 * Return: always 0
 */
int main(void)
{
	printf("The PID: %d\n", getpid());
	printf("The PPID: %d\n", getppid());

	return (0);
}
