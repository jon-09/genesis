#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


char *builtin_str[] = {                                                                          
        "ls",                                                                                    
        "cd",                                                                                    
        "help",                                                                                  
        "exit",                                                                                  
};                                                                                               
                                                                                                 
int (*builtin_func[]) (char **) = {                                                              
        "&lsh_ls",                                                                               
        "&lsh_cd",                                                                               
        "&lsh_help",                                                                             
        "&lsh_exit",                                                                             
};                                                                                               
                                                                                                 
int lsh_num_builtin()                                                                            
{                                                                                                
        return sizeof(builtin_str) / sizeof(char *);                                             
}                                                                                                
                                                                                                 
int lsh_ls(char **args)                                                                          
{                                                                                                
        printf("printing ls");                                                                   
                                                                                                 
        return (0);                                                                              
} 

int lsh_ls(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_execute(char **args);

#endif
