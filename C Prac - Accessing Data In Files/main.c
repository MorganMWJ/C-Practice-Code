/* 
 * File:   main.c
 * Author: mwj7
 *
 * Created on 04 December 2015, 12:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*
 * 
 */
int main(int argc, char** argv) {
    
    char filename[80];
    char my_buffer[100];
    ssize_t status;/*type from unistd.h*/
    int i;
    int startPos;
    
    printf("Please enter the path to a file to read from:");
    scanf( "%s", filename);
    
    /*
     STDIN_FILENO is a macro defined in unistd which has the value 0,
     * that is, the file descriptor number of standard input.
     */
    
    int openFile = open(filename, O_RDONLY);
    //open() returns -1 if fails and set global errno 
    if(openFile == -1){
        printf("Problem opening file, Program Will Exit.");
        return (EXIT_FAILURE);
    }
    
    printf("Please enter the number of characters you want to skip:");
    scanf( "%d", &startPos);
    
    int pos = lseek(openFile,startPos,SEEK_SET);
    if(pos<startPos){
        printf("Cant skip more characters than are in the file.");
        return (EXIT_FAILURE);
    }
    
    //read reads a number of bytes(sizeof(my_buffer)) from a file(openFile) into a char array(my_buffer)
    //returns number of bytes read in (-1, if error) (0, if end of file))
    status = read(openFile, my_buffer, sizeof(my_buffer));
    
    while(status > 0)
    {
        printf("WE READ IN %ld BYTES\n", (long)status);
        for(i=0;i<status;i++){
            printf("The code of byte %d is %d(%c)\n",i,my_buffer[i],my_buffer[i]);
        }
        status = read(openFile, my_buffer, sizeof(my_buffer));
    }
    
    return (EXIT_SUCCESS);
}

