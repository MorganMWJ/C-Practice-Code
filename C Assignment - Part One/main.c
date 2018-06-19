/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Morgan
 *
 * Created on November 30, 2015, 11:57 PM
 */

#include <stdio.h>
#include <stdlib.h>  
#include "competition.h"

/*
 * 
 */
int main(int argc, char** argv) {
    FILE* file;
    struct event competition;

    //Get the name of the file from the user
    //open file, exit if the file does not exist
    file = openFile(getFileName());
    if(file==NULL){
        printf("ERROR: Could not open file");
        return(EXIT_FAILURE);
    }
    
    //read the competitors from the file and store them in the BST
    if(buildCompetitors(file, &competition)==false){
        return(EXIT_FAILURE);        
    }
    
    //close file
    fclose(file);
    
    //print out the competitors
    printOutput(&competition);
    
    return (EXIT_SUCCESS);
}

/*Reads a file name from the user*/
char* getFileName(){
    char* fileName = malloc(sizeof(char) * 30);
    
    printf("Please enter the name of the file: ");
    scanf( "%s", fileName);
    
    return fileName;
}