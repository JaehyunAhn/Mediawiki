/*****************************
  * sogo
  * 2013/12/5 ~
  * file triver ver 2
  * input: keyboard (directory)
  * output: all files in directory
  ****************************/
#include <stdio.h>
#include <string.h>
#include <dirent.h>
/****************************
  * input:  1. directory 
            2. repo(sitory) array
            3. repo count
            
  * output: 1. files in repository
            2. save other directory
  *
  **************************/
void folder_thriver(char *entry, char *repo, int *repo_count);

int main (int arc, char **argv)
{
    // input exception handler
    char current[2];
    if(arc == 1) 
        return 0;
    current[0] = argv[1][0];
    current[1] = argv[1][1];
    if(strcmp(current,"./") != 0)
        return 0;
    
    // folder thrive
    char dir_route[1000][2000];
    int dir_count = 0;
    strcpy(dir_route[dir_count],argv[1]);
    folder_thriver(argv[1], *dir_route, &dir_count);
    
    return 1;
}

void folder_thriver(char *entry, char *repo, int *repo_count)
{
    printf("%s\n",&repo[0]);
}
