/* 
 * File:   main.c
 * Author: mwj7
 *
 * Created on 03 December 2015, 11:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
/*
 * 
 */
int main(int argc, char** argv) {
    char directory[50];
    char chosenFile[50];
    
    printf("Enter a directory to print it's contents:\n");
    scanf(" %s", directory);
    
    //using a type and a structure from dirent.h
    DIR * current_dir_Ptr;
    struct dirent * next_entry_ptr;
    
    current_dir_Ptr = opendir(directory);
    next_entry_ptr = readdir(current_dir_Ptr);
    
    printf("BELOW IS THE LIST OF DIRECTORY ENTRIES:\n");

    while(next_entry_ptr != NULL){
        printf("File number %d: %s\n",(int)next_entry_ptr->d_ino,next_entry_ptr->d_name);
        next_entry_ptr = readdir(current_dir_Ptr);
    }
 
    printf("\nPlease enter the name of a directory entry to view it's information: ");
    scanf(" %s",chosenFile);
    
    struct stat sb;
    int openSuccessStatus = stat(chosenFile,&sb);
    if(openSuccessStatus<0){
        printf("Cannot open file [%s]\n",chosenFile);
        return (EXIT_FAILURE);
    }
    printf("\nBELOW IS THE INFORMATION FOR [%s]:\n",chosenFile);
    printf("Size of file: %ld\n",(long)sb.st_size);
    printf("Time of last modification: %s",ctime(&(sb.st_mtim)));
    printf("Number of hard links: %d\n",(int)sb.st_nlink);
    
    closedir(current_dir_Ptr);
    return (EXIT_SUCCESS);
}

