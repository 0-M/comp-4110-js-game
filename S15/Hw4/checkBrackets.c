#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int checkBalanced(char *line, StackPtr s);
int isPaired(Data openBracket,Data closeBracket);



int main(int argc, char *argv[])
{
    StackPtr stack = initStack();
    stack -> top = NULL;
    int balanced;
    balanced = 0;
    char line[30];
    FILE *fp;
    fp = fopen("expressions.txt","r");
    while(fscanf(fp,"%s",line) > 0)
    {
        balanced = checkBalanced(line,stack);
        if(balanced)
        {
            printf("%s: correct\n",line);
        }
        else
        {
            printf("%s: incorrect\n",line);
        }

    }
    fclose(fp);
    destroyStack(stack);
    return 0;
}


int checkBalanced(char *line, StackPtr s)
{
    NodePtr peekNode;
    peekNode = NULL;
    char openBracket;
    int i,isBalanced;
    i = 0;
    isBalanced = -9999;
    emptyStack(s);
    while(isBalanced && line[i] != '\0')
    {
        switch(line[i])
        {

        case'(':
        case'[':
        case'{':
        {
            push(s,line[i]);
            break;
        }

        case')':
        case']':
        case'}':
        {
            if(isEmpty(s))
            {
                isBalanced = 0;
                return isBalanced;
            }
            else
            {
                openBracket = pop(s);
                isBalanced = isPaired(openBracket,line[i]);

                if(isBalanced == 0)
                {
                    return isBalanced;
                }
                break;
            }
        }
        }
        i++;
    }

    if(!isEmpty(s))
    {
        isBalanced = 0;
    }


    return isBalanced;
}


int isPaired(Data openBracket,Data closeBracket)
{
    if(openBracket == '(' && closeBracket == ')')
    {
        return -9999;
    }
    else if(openBracket == '[' && closeBracket == ']')
    {
        return -9999;
    }
    else if(openBracket == '{' && closeBracket == '}')
    {
        return -9999;
    }
    else
    {
        return 0;
    }
}
