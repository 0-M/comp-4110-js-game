#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    NodePtr peekNode;
    peekNode = NULL;
    Data popS,peekS;
    StackPtr stack = initStack();
    stack -> top = NULL;
    //push(stack,1);
   // push(stack,2);
    //push(stack,3);
   // push(stack,4);
   // push(stack,5);
    printf("\n\n");

    while(!isEmpty(stack))
    {
        peekS = peek(stack);
        if(peekS > 0)
        {
            printf("The data at the top of the stack is %d.\n",peekS);
        }

        printf("Printing out the whole stack:\n");
        peekNode = stack -> top;
        while(peekNode != NULL)
        {
            printf("%d,",peekNode -> data);
            peekNode = peekNode -> next;
        }
        printf("\n");
        popS = pop(stack);
        if(popS > 0)
        {
            printf("The data at the top of the stack %d has been removed\n\n",popS);
        }

    }


    printf("Trying to pop another element.\n");
    pop(stack);
    emptyStack(stack);
    destroyStack(stack);


    return 0;
}
