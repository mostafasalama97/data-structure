#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node *Next;
};

Node *Rear= NULL, *front = NULL;

void ENQUE (int data){
    Node * newnode=(Node *) malloc (sizeof(Node));
    newnode->data=data;
    newnode->Next=NULL;
    if (front == NULL){
        front=Rear=newnode;
    }
    else {
        Rear->Next=newnode;
        Rear=newnode;
    }
}

int DEQUE (int *data){
    Node *fre;
    if(front == NULL){
        Rear=NULL;
        return 0;
    }
    *data=front->data;
    fre=front;
    front=front->Next;
    free(fre);
    return 1;
}
