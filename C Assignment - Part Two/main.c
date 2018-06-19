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
    
    //loop the menu until user types 'q' to quit
    bool quit = false;
    do{
        char choice = getPrintChoice();
        
        if(choice == 'q'){
            quit = true;           
        }
        else{
            //print output in format that depends on user choice
            printOutput(&competition, choice);
        }
    }while(!quit);
    
    return (EXIT_SUCCESS);
}

/*BELOW ARE INPUT FUNCTIONS*/

/*Reads a file name from the user*/
char* getFileName(){
    char* fileName = malloc(sizeof(char) * 30);
    
    printf("Please enter the name of the file: ");
    scanf( "%s", fileName);
    
    return fileName;
}

/*Get a menu choice from the user*/
char getPrintChoice(){
    char* menu = "1. Print Competition Results\n2. Print Competitor Contact Details\nq. Quit";
    char input;
    
    do{
        printf("\nPlease choose a menu option:\n%s", menu);
        scanf(" %c", &input);
    }
    while(input != '1' && input != '2' && input != 'q');
    
    return input;
}