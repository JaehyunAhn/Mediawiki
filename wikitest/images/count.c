/********************
  * 2013/12/5 sogo
  * sogosonnet@naver.com
  * file triver
  * input: current directory
  * output: all files in current directory
  *******************/
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void main (void)
{
    int file_count = 0;
    DIR * dirp;
    struct dirent * entry;
    
    dirp = opendir("./");
    while(( entry = readdir(dirp)) != NULL) {
        if(entry->d_type == DT_REG) {
            printf("%s\n",entry->d_name);
            file_count++;
        }
        if(entry->d_type == DT_DIR) {
            printf("[dir] %s\n",entry->d_name);
        }
    }
    closedir(dirp);
    printf("File count: %d\n",file_count);
}
