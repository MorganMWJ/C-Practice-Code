#include <stdio.h>
#include <stdlib.h>  
#include <math.h>
#include "competition.h"

void printOutput(struct event* theCompetition){
    //print header with name and date
    printf("Competition: %s Date: %s\n", theCompetition->name, theCompetition->date);
    printf("%-11s%-19s%14s%14s%14s%14s\n","NAME","competitor number", "Cucumber", "Carrot", "Runner Bean", "Total Length");
    printf("==========================================================================================\n");
    
    //print each competitor from the binary tree
    printBST(theCompetition->root);
}

/*Prints the nodes of the binary tree in-order*/
/*Algorithm (similar code) for in-order traversal 
  taken from Berrnie Tiddemen CS21120 lecture slide*/
void printBST(struct competitor* node){
    if(node==NULL){
        return;
    }
    
    //print the left subtree using recursion
    printBST(node->leftChild);
    printCompetitor(node);
    
    //print the right subtree using recursion
    printBST(node->rightChild);
}

/*Print formats a competitors competition results*/
void printCompetitor(struct competitor* competitor){
    printf("%-19s%-15d%-14s%-14s%-14s%-14s\n",
            competitor->name,
            competitor->compID,
            displayInches(competitor->cucumberLen),
            displayInches(competitor->carrotLen),
            displayInches(competitor->beanLen),
            displayInches(totalInches(competitor)));
}

/*formats a total amount of inches to be displayed in feet and inches*/
char* displayInches(float totalInches){
    char*  display = malloc(sizeof(char) * 10);
    
    //below is same as use of modulus(%) couldn't use modulus because operands are be floats
    float displayInches = fmod(totalInches, INCHES_PER_FOOT);
    int displayFeet = (totalInches-displayInches)/INCHES_PER_FOOT;
    
    sprintf(display, "%dft%5.1fin", displayFeet, displayInches);
    
    return display; 
}
