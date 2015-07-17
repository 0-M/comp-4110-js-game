typedef int Data;

typedef struct node {

Data data;
struct node *next;
}Node,*NodePtr;

typedef struct que
{
    NodePtr head;
    NodePtr tail;
    int sizeQue;
}Queue,*QueuePtr;

QueuePtr initQueue(); //Initialize the queue
void destroyQueue(QueuePtr que); //Destroy the queue
void enqueue(QueuePtr que,Data d); //Add the the end(tail)
Data dequeue(QueuePtr que); //Remove from the start(head)
int isEmpty(QueuePtr que); //Checks if the queue is empty or not
void emptyQueue(QueuePtr que); //Empties the queue
Data getFront(QueuePtr que); //Returns the data at the front of the queue(head)
int getSize(QueuePtr que); //Returns the size of the queue

