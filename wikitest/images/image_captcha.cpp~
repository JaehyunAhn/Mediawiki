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

// define whether to use approximate nearest-neighbor search
#define USE_FLANN

IplImage *image = 0;

double
compareSURFDescriptors( const float *d1, const float *d2, double best, int length)
{
    double total_cost = 0;
    assert( length % 4 == 0 );
    for( int i = 0; i < length; i+= 4 )
    {
        double t0 = d1[i] - d2[i];
        double t1 = d1[i+1] - d2[i+1];
        double t2 = d1[i+2] - d2[i+2];
        double t3 = d1[i+3] - d2[i+3];
        total_cost += t0*t0 + t1*t1 + t2*t2 + t3*t3;
        if( total_cost > best )
            break;
    }
    return total_cost;
}
/*
int
naiveNearestNeighbor( const float* vec, int laplacian,
                      const CvSeq* model_keypoints,
                      const CvSeq* model_descriptors )
{
    int length = (int)(model_descriptors->elem_size/sizeof(float));
    int i, neighbor = -1;
    double d, dist1 = 1e6, dist2 = 1e6;
    CvSeqReader reader, kreader;
    cvStartReadSeq( model_keypoints, &kreader, 0 );
    cvStartReadSeq( model_descriptors, &reader, 0 );

    for( i = 0; i < model_descriptors->total; i++ )
    {
        const CvSURFPoint* kp = (const CvSURFPoint*)kreader.ptr;
        const float* mvec = (const float*)reader.ptr;
        CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
        CV_NEXT_SEQ_ELEM( reader.seq->
*/
int 
folder_thriver(char **repo, int *repo_count, int *repo_thrive);

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
    int i;
    int dir_count = 0;
    int repo_count = 0;
    
    dir_route = (char **)malloc(sizeof(char*)*1000);
    for(i=0; i<1000; i++)
        dir_route[i] = (char *)malloc(sizeof(char*)*2000);

    strcpy(dir_route[dir_count],argv[1]);

    while(1) {
        if(repo_count != 0)
            if(dir_count == repo_count)
                break;
        if(folder_thriver(dir_route, &dir_count, &repo_count) == 0)
            break;
        if(dir_count == 0)
            break;
    }

    for(i=0; i<1000; i++)
        free(dir_route[i]);
    free(dir_route);

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
int folder_thriver(char **repo, int *repo_count, int *repo_thrive) {
    printf("Current route:%s\n",repo[*repo_count]);

    int init = *repo_count;
    int count = *repo_thrive;
    DIR *dirp;
    struct dirent *entry;
    char init_dir[10000];

    strcpy(init_dir,repo[init]);

    dirp = opendir(init_dir);

    if(dirp) {
        while (( entry = readdir(dirp)) != NULL ) {
            if( entry->d_type == DT_REG ) {
                if ( strstr(entry->d_name,".jpg") )
                    printf("\t\t%s\n",entry->d_name);
                if ( strstr(entry->d_name,".jpeg") )
                    printf("\t\t%s\n",entry->d_name);
                if ( strstr(entry->d_name,".png") )
                    printf("\t\t%s\n",entry->d_name);
            }
            if( entry->d_type == DT_DIR ) {
                if(entry->d_name[0] != '.') {
                    if(count < 1000) {
                        strcpy(repo[count+1],init_dir);
                        strcat(repo[count+1],"/");
                        strcat(repo[count+1],entry->d_name);
                        //printf("%s\n",repo[count+1]);
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
        printf("ERROR: [file_triver.c] There is no directory: %s\n",init_dir);
        return 0;
    }
    *repo_thrive = count;
    *repo_count+=1;
    return 1;
}

void description () {
    printf("That folder has:\n");
}
