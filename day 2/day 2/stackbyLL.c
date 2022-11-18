#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;
struct Node{
    int data;
    Node *prev;
};
Node *top = NULL;

void push (int data){

        Node *newnode=(Node *)malloc (sizeof(Node));
        newnode->data=data;
        if(top==NULL){
            newnode->prev=NULL;
            top=newnode;
        }
        else{
            newnode->prev=top;
            top=newnode;
        }
}
int pop (int *data){
    if(top == NULL){
        return 0;
    }
    *data=top->data;
    top=top->prev;
    return 1;
}

