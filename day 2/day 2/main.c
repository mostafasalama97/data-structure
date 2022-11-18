#include <stdio.h>
#include <stdlib.h>
#include "stackbyLL.h"
int main()
{   int data=0;
    push(10);
    int back=pop(&data);
    if (back==0){
        printf("stack is empty");
        // do any thing if is empty
    }
    else {
        printf("data is %d",data);
        //do any thing here if stack return a value
    }

    return 0;
}
