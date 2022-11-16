#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

typedef struct LinkedList
{
    Node *head, *tail;

}LinkedList;

Node *head = NULL, *tail = NULL;

/*void Add(LinkedList *L, int data)
{
    L->head
}*/

void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \n", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(int data)
{
    Node *node = GetNodeByData(data);

    if(node == NULL)
        return;

    if(node == head)
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {
        /*Node *A = node->Prev;
        Node *B = node->Next;
        A->Next = B;
        B->Prev = A;*/

        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}

void InsertAfter(int data, int afterData){

    Node * node = GetNodeByData(afterData);
    if ( node != NULL){
        Node * newnode = malloc(sizeof(Node));
        newnode->Data= data;
        newnode->Prev= node;
        newnode->Next= node->Next;
        node->Next=newnode;
        if(node == tail){
            tail = newnode;

        }
        else{
            node->Next->Prev=newnode;
        }
    }
    else{
        printf("\n enter a valid value of node ");
    }


}

int GetCount(){
    int counter=0;
    Node *current = head;

    while(current != NULL)
    {
        counter++;
        current = current->Next;
    }

    return counter;
}

int GetDataByIndex(int index){
    int flag =0;
    if (index<GetCount()){
        Node * on =head;
        while(flag < index){
            on=head->Next;
            flag++;
        }
        return on->Data;
    }
    else {
        printf("enter a Valid index in next time");
        printf("\nenter index of node ");
        scanf("%d",&index);
        return GetDataByIndex(index);
    }

}

#endif // LINKEDLIST_H
