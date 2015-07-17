typedef int Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node, *NodePtr;

typedef struct {

NodePtr top;

}Stack, *StackPtr;


StackPtr initStack();
void push(StackPtr s, Data n);
Data pop(StackPtr s);
Data peek(StackPtr s);
int isEmpty(StackPtr s);
void emptyStack(StackPtr s);
void destroyStack(StackPtr s);
