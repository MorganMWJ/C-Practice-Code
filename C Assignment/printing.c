#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <math.h>
#include "competition.h"

void printOutput(struct event* theCompetition){
    char headerLine[83];
    for(int i=0;i<83;i++){
        headerLine[i] = '=';
    }
    
    //print header with name and date
    printf("Competition: %s Date: %s", theCompetition->name, theCompetition->date);
    printf("%s",headerLine);
    
    //print each competitor from the binary tree
    printBST(theCompetition->root);
}

/*Prints the nodes of the binary tree in-order*/
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

void printCompetitor(struct competitor* competitor){
    printf("%s%d%s%s%s%s",
            competitor->name,
            competitor->compID,
            displayInches(competitor->cucumberLen),
            displayInches(competitor->carrotLen),
            displayInches(competitor->beanLen),
            displayInches(totalInches(competitor)));
}

char* displayInches(float totalInches){
    char*  display = malloc(sizeof(char) * 10);
    
    //below is same as use of modulus(%) couldn't use modulus because operands would be floats
    float displayInches = totalInches - (totalInches/INCHES_PER_FOOT);
    int displayFeet = (totalInches-displayInches)/INCHES_PER_FOOT;
    
    sprintf(display, "%dft %1.1fft", displayFeet, displayInches);
    
    return display; 
}
