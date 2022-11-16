#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main()
{
    int index =0 ;
    /*LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 3);*/

    Add(3);
    Add(5);
    Add(7);
    Add(9);
    InsertAfter(100,9);
    InsertAfter(1,3);
    InsertAfter(50,7);
    Display();
    printf("the number of nodes = %d", GetCount());
    printf("\nenter index of node ");
    scanf("%d",&index);
    printf("\ndata in index = %d", GetDataByIndex(index));

    return 0;
}
