#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "competition.h"

FILE* openFile(char* filename){
    FILE* filePtr;
    filePtr = fopen(filename,"r");
    return filePtr;
}

/*This function reads in the competition data and stores it in a BST*/
bool buildCompetitors(FILE* compFile, struct event* competition){
    
    //read header
    if(!readHeader(compFile, competition)){
        printf("ERROR: Failed to read from file.");
        return false;   
    }
   
    int counter = 1;
    while(1){  
        //ptr to a new competitor
        struct competitor* newComp;
        
        //create space and defaults for the new competitor
        if((newComp = createComp(counter++))==NULL){
            printf("ERROR: OP refused to provide enough memory.");
            return false;
        }
        
        //read competitor details from file 
        if(readCompetitor(compFile, newComp)==false){
            printf("ERROR: Failed to read from file.");
            return false;
        }
        
        //add that competitor to the binary tree data structure
        addToBST(newComp, competition); 
    }
    return true;
}

bool readHeader(FILE* compFile, struct event* competition){
    if(!readString(compFile, competition->name)) return false;
    
    if(!readString(compFile, competition->date)) return false;
    
    return true;
}

struct competitor* createComp(int id){
    //create space in memory
    struct competitor* newComp = (struct competitor*) malloc(sizeof(struct competitor));
    
    //return if memory allocation failed
    if(newComp==NULL){
        return newComp;
    }
    
    //assign competitor ID
    newComp->compID = id;
    //assign initial children to be NULL
    newComp->leftChild = NULL;
    newComp->rightChild = NULL;   
    
    return newComp;
}

bool readCompetitor(FILE* compFile, struct competitor* newComp){
    //read in the six lines of data into the new competitor structure 
    //return false if any read fails    
    if(!readString(compFile, newComp->name)) return false;    

    if(!readString(compFile, newComp->address)) return false;
   
    if(!readString(compFile, newComp->phoneNumber)) return false;
   
    if(!readLength(compFile, &newComp->cucumberLen)) return false;
   
    if(!readLength(compFile, &newComp->carrotLen)) return false;
   
    if(!readLength(compFile, &newComp->beanLen)) return false;   
    
    return true;
}

bool readString(FILE* compFile, char* strVar){
    int readItems;
    
    //if fscanf() reads wrong input return false
    readItems = fscanf(compFile,"%[^\n]\n",strVar);
    if(readItems != 1){
        return false;
    }
    
    return true;
}

bool readLength(FILE* compFile, float* lenVar){
    int feet;
    float inches;
    int readItems;
    
    //if fscanf() reads wrong input return false
    readItems = fscanf(compFile,"%d %f\n",&feet,&inches);
    if(readItems != 2){
        return false;
    }
    *lenVar = toInches(feet,inches);
    return true;
}

/*This function adds a competitor to the binary tree
 It takes both the tree and the competitor as parameters*/
void addToBST(struct competitor* compToAdd, struct event* competition){
    if(compToAdd->compID == 1){
        competition->root=compToAdd;
        return;
    }
    //find the node that the new competitor will become a child of
    struct competitor* nodeToAppendTo = getNodeToAppendTo(totalInches(compToAdd), competition->root);
    //add the competitor as the the right or left child of this node
    if(totalInches(compToAdd) < totalInches(nodeToAppendTo)){
        nodeToAppendTo->leftChild = compToAdd;
    }
    else{
        nodeToAppendTo->rightChild = compToAdd;
    }
}

/*This function is used by the addToBST function to find the node that the new
 competitor structure will become a child of*/
struct competitor* getNodeToAppendTo(float valueToInsert, struct competitor* currentComp){
    if(valueToInsert < totalInches(currentComp)){
        if(currentComp->leftChild == NULL){
            return currentComp;
        }
        return getNodeToAppendTo(valueToInsert, currentComp->leftChild);
    }
    else{
        if(currentComp->rightChild == NULL){
            return currentComp;
        }
        return getNodeToAppendTo(valueToInsert, currentComp->rightChild);
    }
}

float toInches(int feet, float inches){
    return (feet*INCHES_PER_FOOT) + inches;
}

float totalInches(struct competitor* competitor){
    float a = competitor->cucumberLen;
    float b = competitor->carrotLen;
    float c = competitor->beanLen;
    return a+b+c;
}