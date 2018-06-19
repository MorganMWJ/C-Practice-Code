/* 
 * File:   main.c
 * Author: mwj7
 *
 * Created on 17 November 2015, 12:47
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"



LLNode* buildBookNode(char* title,char* author,long ISBN){
    //need to use malloc() to create space for the structure to return 
    //because the structure will be used outside this scope
    LLNode* newBook = (LLNode*) malloc(sizeof(LLNode));
    
    strncpy(newBook->title, title, 50);
    strncpy(newBook->author, author, 30);
    newBook->ISBN = ISBN;
    newBook->nextNode = NULL;
    
    return newBook;
}


//order by ISBN number
void insertBook(LLNode* head, LLNode* newBook){
    LLNode* currentNode = head->nextNode;
    

    
    while(1){
        if(head->nextNode == NULL){
            head->nextNode = (struct llnode_t*) newBook;
            return;
        }
        else if(newBook->ISBN < currentNode->ISBN){
            //save current node (and its next node
            LLNode* previousCurrentNode = currentNode;
            //overwrite old current node with new book
            currentNode = (struct llnode_t*) newBook;
            //assign new current node its old self as a link
            currentNode->nextNode = (struct llnode_t*) previousCurrentNode;
            head->nextNode = currentNode;
           // head = currentNode;
            return;
        } 
        else{
            currentNode = currentNode->nextNode;
        }
    }
}

void displayList(LLNode* head){
    LLNode* temp = head->nextNode;
    printf("ALL Books:\n");
    //%lu is the format specifier for a long
    printf("ISBN: %lu|Title: %s|Author: %s\n",temp->ISBN,temp->title,temp->author);
    while(temp->nextNode!=NULL){
        temp = temp->nextNode;
        printf("ISBN: %lu|Title: %s|Author: %s\n",temp->ISBN,temp->title,temp->author);
    }
}

//Returns ture if the book exists in the list otherwise false
void displayNode(long isbn, LLNode* head){
    LLNode* temp = head;
    
    if(temp->ISBN==isbn){
        printf("ISBN: %lu|Title: %s|Author: %s\n",temp->ISBN,temp->title,temp->author);
        return;
    }    
    
    while(temp->nextNode!=NULL){
        temp = temp->nextNode;
        if(temp->ISBN==isbn){
            printf("ISBN: %lu|Title: %s|Author: %s\n",temp->ISBN,temp->title,temp->author);
            return;
        }
    }
    
    printf("\n\nThere is no book with the ISBN number: %lu in the list.",isbn);
}
/*
 * 
 */
int main(int argc, char** argv) {
    //dummuy node#
    LLNode * head = (LLNode *)malloc(sizeof(LLNode)); 
    head->nextNode=NULL;
   
    insertBook(head,buildBookNode("start","morgan",998765));
    
    //create two books
    insertBook(head, buildBookNode("The noted","Byian",456789));
    insertBook(head, buildBookNode("Breakfast of champions","Kurt",234566));
    
    displayList(head);
    
    displayNode(234566,head);
    return (EXIT_SUCCESS);
}

