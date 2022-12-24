#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main()
{
    Tree tree = {.Root = NULL};

    Add(&tree, 55);
    Add(&tree, 10);
    Add(&tree, 12);
    Add(&tree, 97);
     Display(tree.Root);
    int Result=GetMaxDepth(tree.Root);
    printf("\n Max Depth is: %d", Result);


    return 0;
}
