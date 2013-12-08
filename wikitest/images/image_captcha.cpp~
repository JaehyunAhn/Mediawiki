 /*
  * Author: Sogo
  * sogosonnet@gmail.com
  * Contents: Image Captcha
  * Date: 2013/12/7 ~
  * input: keyboard (directory)
  * output: all files in directory
  *
  *
  * <Open Source provider>
  * Author: Liu Liu
  * Contents: SURF Image Comparison Algorithm
  * liuliu.1987+opencv@gmail.com
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include <cv.h>
#include <highgui.h>
#include <ctype.h>

#include <iostream>
#include <vector>

using namespace std;

IplImage *image = 0;

int 
image_thriver(char **repo, int *repo_count, int *repo_thrive, FILE *fp);

void 
description();

int main (int arc, char **argv) {
    /* input exception handler */
    char current[2];
    if(arc == 1) 
        return 0;
    
    current[0] = argv[1][0];
    current[1] = '\0';

    if(strcmp(current,".") != 0)
        return 0;

    /* Description */
    description();
    
    /* folder thrive */
    char **dir_route;
    int i,j;
    int dir_count = 0;
    int repo_count = 0;
    
    dir_route = (char **)malloc(sizeof(char*)*1000);
    for(i=0; i<1000; i++)
        dir_route[i] = (char *)malloc(sizeof(char*)*2000);

    strcpy(dir_route[dir_count],argv[1]);

    /* file open */
    FILE *fp = fopen("metadata_image.txt","w");
    if( fp == NULL )
    {
        printf("File writing error\n");
        return 0;
    }

    while(1) {
        if(repo_count != 0)
            if(dir_count == repo_count)
                break;
        if(image_thriver(dir_route, &dir_count, &repo_count, fp) == 0)
            break;
        if(dir_count == 0)
            break;
    }

    /* close sample data file */
    fclose(fp);

    /* image comparison logic */
    FILE *f_in = fopen("metadata_image.txt","r");
    FILE *f_out = fopen("report.txt","w");
    if(fp == NULL)
    {
        printf("File open error\n");
        return 0;
    }

    i = 0;
    while( fscanf(f_in,"%s",dir_route[i]) != EOF )
        i++;
    
    int total_number_of_dir = i;
    char object_filename[1000];
    char scene_filename[1000];
    for(i=0; i < total_number_of_dir; i++)
    {
        strcpy(object_filename,dir_route[i]);
        
        for(j = i+1; j < total_number_of_dir; j++)
        {
            strcpy(scene_filename,dir_route[j]);
            //printf("%s :: %s\n",object_filename,scene_filename);

            CvMemStorage* storage = cvCreateMemStorage(0);
            static CvScalar colors[] =
            {
                {{0,0,255}},
                {{0,128,255}},
                {{0,255,255}},
                {{0,255,0}},
                {{255,128,0}},
                {{255,255,0}},
                {{255,0,0}},
                {{255,0,255}},
                {{255,255,255}}
            };

            IplImage* object = cvLoadImage( object_filename, CV_LOAD_IMAGE_GRAYSCALE );
            IplImage* image = cvLoadImage( scene_filename, CV_LOAD_IMAGE_GRAYSCALE );
            if( !object || !image )
            {
                fprintf( stderr, "Can not load %s and/or %s\n"
                        "Usage: image_captcha [<object_filename> <scene_filename>]\n",
                        object_filename, scene_filename);
                exit(-1);
            }// 234

            IplImage* object_color = cvCreateImage(cvGetSize(object), 8, 3 );
            cvCvtColor( object, object_color, CV_GRAY2BGR );

            CvSeq *objectKeypoints = 0, *objectDescriptors = 0;
            CvSeq *imageKeypoints = 0, *imageDescriptors = 0;
            CvSURFParams params = cvSURFParams(500, 1);

            double tt = (double)cvGetTickCount();
            cvExtractSURF( object, 0, &objectKeypoints, &objectDescriptors, storage, params );
            printf("Object Descriptors: %d\n", objectDescriptors->total);
            cvExtractSURF( image, 0, &imageKeypoints, &imageDescriptors, storage, params );
            printf("Image Descriptors: %d\n", imageDescriptors->total);
            tt = (double)cvGetTickCount() - tt;
            printf("Extraction time = %gms\n", tt/(cvGetTickFrequency()*1000.));
        }
    }

    /* free buffer list */
    for(i=0; i<1000; i++)
        free(dir_route[i]);
    free(dir_route);
    /* close image captcha file */
    fclose(f_in);
    fclose(f_out);

    return 1;
}

/****************************
  * input:  1. repo(sitory) array
  *         2. repo count
  *          
  * output: 1. 100 ~ 799 px image name
  *         2. that directory
  * return: == 1 : everything goes correct
            == 0 : return NULL
  *
  ***************************/
int image_thriver(char **repo, int *repo_count, int *repo_thrive, FILE *fp) {
    // printf("Current route:%s\n",repo[*repo_count]);

    int file_counter = 0;
    bool img_flag = false;
    char *str1 = NULL;
    char *str2 = NULL;
    int init = *repo_count;
    int count = *repo_thrive;
    DIR *dirp;
    struct dirent *entry;
    char buff[10000];


    strcpy(buff,repo[init]);

    dirp = opendir(buff);

    if(dirp) {
        while (( entry = readdir(dirp)) != NULL ) {
            if( entry->d_type == DT_REG ) {
                if ( strstr(entry->d_name,".jpg") )
                    img_flag = true;
                    //printf("\t\t%s\n",entry->d_name);
                if ( strstr(entry->d_name,".jpeg") )
                    img_flag = true;
                    //printf("\t\t%s\n",entry->d_name);
                if ( strstr(entry->d_name,".png") )
                    img_flag = true;
                    //printf("\t\t%s\n",entry->d_name);
                if ( img_flag )
                {
                    str1 = entry->d_name;
                    str2 = strstr(entry->d_name,"px");
                    if((str2 != NULL) && (strlen(str1) - strlen(str2) == 3))
                    {
                        if(entry->d_name[0] <= '7') 
                            // Filter image 100 ~ 799 px
                            strcpy(buff,entry->d_name);
                    }
                }
                file_counter++;
            }
            if( entry->d_type == DT_DIR ) {
                if(entry->d_name[0] != '.') {
                    if(count < 1000) {
                        strcpy(repo[count+1],buff);
                        strcat(repo[count+1],"/");
                        strcat(repo[count+1],entry->d_name);
                        count++;
                    }
                    else {
                        printf("ERROR: [file_triver.c] Repository Count over 1000.\n");
                        return 0;
                    }
                }
            }
        }
        if( img_flag )
        {
            if( strcmp(repo[*repo_count],buff) != 0)
            {
                printf("Current route:%s\n",repo[*repo_count]);
                printf("\t\thas %s\n",buff);

                if(fp != NULL)
                {
                    char file_name[10000];
                    strcpy(file_name,repo[*repo_count]);
                    strcat(file_name,"/");
                    strcat(file_name,buff);
                    strcat(file_name,"\n");
                    fprintf(fp,file_name);
                }
                else
                {
                    printf("ERROR: [file_triver.c] cannot open file.\n");
                    return 0;
                }
            }
        }
        closedir(dirp);
    }
    else {
        printf("ERROR: [file_triver.c] There is no directory: %s\n",buff);
        return 0;
    }
    *repo_thrive = count;
    *repo_count+=1;
    return 1;
}

void description () {
    printf("That folder has:\n");
}
