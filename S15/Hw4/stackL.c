#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackPtr initStack();
void push(StackPtr s, Data n);
int isEmpty(StackPtr s);
Data pop(StackPtr s);
Data peek(StackPtr s);
void emptyStack(StackPtr s);
void destroyStack(StackPtr s);


StackPtr initStack()
{
    StackPtr stack = (StackPtr)malloc(sizeof(Stack));
    stack -> top = NULL;
    return stack;
}

void push(StackPtr s, Data n)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode -> data = n; //Assigns the data to the new node
    newNode -> next = s -> top; //Assigns the next node to be the current first node
    s -> top = newNode; //Makes the new node the first node
    //printf("Adding %d to the top of the stack.\n",n);
}
int isEmpty(StackPtr s)
{
    return(s -> top == NULL);
}


Data pop(StackPtr s)
{

    if(isEmpty(s))
    {
        printf("The stack is empty, nothing to remove.\n");
        return -9999;
    }
    else
    {
        Data hold = s -> top -> data;
        NodePtr temp = s->top;
        s -> top = s-> top -> next;
        free(temp);
        return(hold);

    }
}

Data peek(StackPtr s)
{
    if(isEmpty(s))
    {
        //printf("The stack is empty, nothing to peek.\n");
        return -9999;
    }
    else
    {
        return(s -> top -> data);
    }
}

void emptyStack(StackPtr s)
{
    while(s -> top != NULL)
    {
        pop(s);
    }


    //printf("The stack has been successfuly emptied.\n");
}

void destroyStack(StackPtr s)
{
    if(isEmpty(s))
    {
        free(s);
    }
    else
    {
        emptyStack(s);
        free(s);
    }

    printf("The stack has been successfully destroyed");
}
