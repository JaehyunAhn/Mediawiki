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

int folder_thriver(char *repo, int *repo_count);
void description();

int main (int arc, char **argv) {
    // input exception handler
    char current[2];
    if(arc == 1) 
        return 0;
    
    current[0] = argv[1][0];
    current[1] = argv[1][1];
    
    if(strcmp(current,"./") != 0)
        return 0;

    // Description
    description();
    
    // folder thrive
    char dir_route[1000][2000];
    int dir_count = 0;
    
    strcpy(dir_route[dir_count],argv[1]);
    
    while(1) {
        if(folder_thriver(*dir_route, &dir_count) == 0)
            break;
        if(dir_count == 0)
            break;
    }
    return 1;
}

/****************************
  * input:  1. repo(sitory) array
  *         2. repo count
  *          
  * output: 1. files in repository
  *         2. save other directory
  * return: == 1 : everything goes correct
            == 0 : return NULL
  *
  ***************************/
int folder_thriver(char *repo, int *repo_count) {
    printf("%s\n",&repo[*repo_count]);

    int file_count = 0;
    int init = *repo_count;
    int count = init;
    DIR *dirp;
    struct dirent *entry;
    char init_dir[50];
    strcpy(init_dir,&repo[init]);

    dirp = opendir(&repo[*repo_count]);
    if(dirp) {
        while (( entry = readdir(dirp)) != NULL ) {
            if( entry->d_type == DT_REG ) {
                printf("%s\n",entry->d_name);
                file_count++;
            }
            if( entry->d_type == DT_DIR ) {
                if(entry->d_name[0] != '.') {
                    printf("[dir] %s\n",entry->d_name);
                    if(count < 1000) {
                        strcpy(&repo[count+1],init_dir);
                        strcat(&repo[count+1],entry->d_name);
                        printf("%d :",count);
                        printf("%s\n%s%s\n",&repo[count+1],&repo[init]);
                        count++;
                    }
                    else {
                        printf("ERROR: [file_triver.c] Repository Count over 1000.\n");
                        return 0;
                    }
                }
            }
        }
        closedir(dirp);
    }
    else {
        printf("ERROR: [file_triver.c] There is no directory.\n");
        return 0;
    }
    printf("\n************************************\n");
    printf("\t\tSUMMARY\n");
    printf("Files:\t\t\t%d\n",file_count);
    printf("Detected directories:\t%d\n",count);
    printf("%s\n",&repo[0]);
    printf("%s\n",&repo[1]);
    printf("%s\n",&repo[2]);
    printf("%s\n",&repo[3]);
    *repo_count+=1;
    return 1;
}

void description () {
    printf("Image coparison Starts From:\n");
}
