#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
	char str[30];
	int cnt;

	printf("Custom Terminal\n");
	while (1)
	{
		printf("custom/user$$ ");
		fflush(stdin);
		scanf("%s", str);
		cnt = getchar();
		while (cnt != EOF)
		{
			printf("%s\n", str);
			cnt = getchar();
		}
	}
	return (0);
}
