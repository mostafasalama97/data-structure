#include <stdio.h>
#include <stdlib.h>
#include "stackbyLL.h"
#include "queue.h"
int main()
{   int data=0;
    push(10);
    push(20);
    push(30);
    int back=pop(&data);
    if (back==0){
        printf("stack is empty");
        // do any thing if is empty
    }
    else {
        printf("data is %d",data);
        //do any thing here if stack return a value
    }
    ENQUE(10);
    ENQUE(800);
    ENQUE(300);
    back=DEQUE(&data);
    back=DEQUE(&data);
    back=DEQUE(&data);
    if (back==0){
        printf("\nQUEUE is empty");
        // do any thing if is empty
    }
    else {
        printf("\nQUEUE data is %d",data);
        //do any thing here if stack return a value
    }


    return 0;
}
