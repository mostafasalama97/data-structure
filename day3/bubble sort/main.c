#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};
Node *head = NULL, *tail = NULL;
void swap(Node * index);
void Bublle_sort();
int BinarySearch(int data, Node ** search_Node);
void Add(int data);
void Display();


int main()
{
     Node * search_Node = NULL;
     int x=0;
     Add(10);
     Add(30);
     Add(20);
     Add(50);
     Add(40);
      printf("befor sorting\n");
     Display();
     Bublle_sort();
      printf("\nafter sorting\n");
     Display();
     printf("enter data for BinarySearch : ");
     scanf("%d",&x);
     int check = BinarySearch(x,&search_Node);
     if (check == 1)
     {
            printf("\ndata found = %d \n", search_Node->Data);
     }
     else
     {
            printf("\ndata not found ");
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
int GetCount(Node * start,Node * end){
    int counter=0;
    Node *current = start;

    while(current != end)
    {
        counter++;
        current = current->Next;
    }

    return counter;
}

int BinarySearch(int data, Node ** search_Node)//binary search
{
    Bublle_sort();
    Node *start , *end ,*mid;
    start=mid=head;
    end=tail;
    int mid_size ,i=0;
    while(start != NULL && end != NULL && start ->Prev != end ){
        mid=start;
        mid_size= GetCount(start,end) /2;
        for(i=0;i<mid_size;i++)
        {
            mid=mid->Next;
        }

        if( mid->Data == data ){
            *search_Node=mid;
            return 1;

        }
        else if(data < mid->Data)
        {

            end=mid->Prev;

        }
        else
        {

            start=mid->Next;


        }
    }
    return 0;

}

void Bublle_sort(){
    Node *index ;
    Node *end =tail ;
    int flage=0;

    while(flage !=1 && head->Next != end ){
        flage=1;
        index = head;

        while (index != end )
        {

            if(index->Data > index->Next->Data)
            {
                  swap(index);
                  flage=0;
            }
            index=index->Next;
        }
        end = end->Prev;

    }
}

void swap(Node * index)
{
    int temp=0;
    temp=index->Data;
    index->Data=index->Next->Data;
    index->Next->Data=temp;
}
