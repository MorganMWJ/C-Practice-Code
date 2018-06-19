#include <stdio.h>
#include <stdlib.h>  
#include <math.h>
#include "competition.h"

/*prints out different header and content dependant on userChoice variable*/
void printOutput(struct event* theCompetition ,char userChoice){
    //print name and date
    printf("\nCompetition: %s Date: %s\n", theCompetition->name, theCompetition->date);
    
    //declare a pointer to a function
    void (*printFunction) (struct competitor*);
    
    //print header depending on users print choice
    switch(userChoice){
        case '1':
            printf("%-11s%-19s%14s%14s%14s%14s\n","NAME","competitor number", "Cucumber", "Carrot", "Runner Bean", "Total Length");
            printf("==========================================================================================\n");
            printFunction = &printResult;
            printBST(theCompetition->root, printFunction);  
            break;
        
        case '2':
            printf("Competitor Contact Details.\n");
            printFunction = &printContact;
            printBST(theCompetition->root, printFunction);
            break;
        //no default case because only valid user choices are passed to this function
    }
}


/*Prints the nodes of the binary tree in-order
  Takes in a different print function depending on user choice
 **Algorithm (similar code) for in-order traversal taken from 
 Berrnie Tiddemen CS21120 lecture slide**/
void printBST(struct competitor* node, void (*nodePrintAction)(struct competitor*)){
    if(node==NULL){
        return;
    }
    
    //print the left subtree using recursion
    printBST(node->leftChild, nodePrintAction);
    (*nodePrintAction)(node);
    
    //print the right subtree using recursion
    printBST(node->rightChild, nodePrintAction);
}

/*Print formats a competitors competition results*/
void printResult(struct competitor* competitor){
    printf("%-19s%-15d%-14s%-14s%-14s%-14s\n",
            competitor->name,
            competitor->compID,
            displayInches(competitor->cucumberLen),
            displayInches(competitor->carrotLen),
            displayInches(competitor->beanLen),
            displayInches(totalInches(competitor)));
}

/*Print formats the contact details of a competitor*/
void printContact(struct competitor* competitor){
    printf("\nCompetitor Name: %s\n", competitor->name);
    printf("Postal Address: %s\n", competitor->address);
    printf("Telephone: %s\n", competitor->phoneNumber);
}

/*formats a total amount of inches to be displayed in feet and inches*/
char* displayInches(float totalInches){
    char*  display = malloc(sizeof(char) * 10);
    
    //fmod() is the same as modulus(%) but for floating point variables
    float displayInches = fmod(totalInches, INCHES_PER_FOOT);
    int displayFeet = (totalInches-displayInches)/INCHES_PER_FOOT;
    
    sprintf(display, "%dft%5.1fin", displayFeet, displayInches);
    
    return display; 
}
