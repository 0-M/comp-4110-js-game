typedef struct Date
{
  int month;
  int day;
}Date,*DatePtr;

typedef struct Data
{
  char courseName[50]; //Maybe switch to dynamic using *
  char assignmentName[50]; //Above
  int points;
  Date dueDate;

}Data,*DataPtr;

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
Data getHighestPtr(QueuePtr que); //Returns the data at the front of the queue(head)
int getSize(QueuePtr que); //Returns the size of the queue
int compare(Data a1,Data a2); //Finds which of the two elements of type data(a1 or a2) has the higher priority
void printData(Data d1); //Prints out data
void display(QueuePtr que); //Prints the whole queue
void getData(QueuePtr que, int num); //Gets num amount of data from user input

