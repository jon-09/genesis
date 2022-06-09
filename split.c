#include <string.h>
#include <stdio.h>

int _split(char *str)
{
   char *token;
   
   token = strtok(str, " ");
  
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, " ");
   }
   
   return(0);
}
int main()
{
	char s[] = "this is it";

	_split(s);
	return (0);
}
