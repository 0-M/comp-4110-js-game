#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pq.h"

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
void getData(QueuePtr que, int num); //Gets data from user input



QueuePtr initQueue() //Initialize the queue
{
    QueuePtr qp = (QueuePtr)malloc(sizeof(Queue));
    qp -> head = NULL;
    qp -> tail = NULL;
    qp -> sizeQue = 0;
    return qp;
}

void destroyQueue(QueuePtr que) //Destroy the queue
{
    if(isEmpty(que))
    {
        free(que);
    }
    else
    {
        emptyQueue(que);
        free(que);
    }

    printf("The queue has been destroyed.\n");
}

void enqueue(QueuePtr que,Data d) //Add based on priority
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    int res = 0;
    int done = 0;
    np -> data = d;
    np -> next = NULL;
    if(que -> head == NULL)
    {
        que -> head = np;
        que -> tail = np;
    }
    else
    {
        NodePtr prev = NULL;
        NodePtr cur = que -> head;
        while(done == 0)
        {
            res = compare(np -> data,cur -> data);
            if(res == 1)//If new node has a higher priority
            {
                if(cur == que -> head) //If placing at the head
                {
                    np -> next = que -> head;
                    que -> head = np;
                    done = 1;
                }
                else
                {
                    np -> next = prev -> next;
                    prev -> next = np;
                    done = 1;
                }
            }
            else if(res == -1)//If the new node has a lower priority
            {
                if(cur == que -> tail)//If the current node is the tail
                {
                    que -> tail -> next = np;
                    que -> tail = np;
                    np -> next = NULL;
                    done = 1;
                }
                else
                {
                    prev = cur;
                    cur = cur -> next;
                }
            }
            else //If they have the same priority(treat the same as if the new one has higher priority)
            {
                if(cur == que -> head) //If placing at the head
                {
                    np -> next = que -> head;
                    que -> head = np;
                    done = 1;
                }
                else
                {
                    np -> next = prev -> next;
                    prev -> next = np;
                    done = 1;
                }
            }
        }
    }
    que -> sizeQue = que -> sizeQue + 1;
}


Data dequeue(QueuePtr que) //Remove from the start(head)
{

    Data hold = que -> head -> data;
    NodePtr temp = que -> head;
    que -> head = que -> head -> next;
    if(que -> head == NULL) //If the queue is now empty
    {
        que -> tail = NULL;
    }
    que -> sizeQue = que -> sizeQue -1;
    free(temp);
    return hold;
}

int isEmpty(QueuePtr que) //Checks if the queue is empty or not
{
    return (que -> head == NULL);
}

void emptyQueue(QueuePtr que) //Empties the queue
{
    while(que -> head != NULL)
    {
        dequeue(que);
    }
    printf("The queue has been emptied.\n");
}


Data getHighestPtr(QueuePtr que) //Returns the data at the front of the queue(head)
{
    return(que -> head -> data);
}

int getSize(QueuePtr que) //Returns the size of the queue
{
    return(que -> sizeQue);
}

int compare(Data a1,Data a2)
{
    if(a1.dueDate.month != a2.dueDate.month)//If they have different months
    {
        if(a1.dueDate.month < a2.dueDate.month) //If the new node is due earlier
        {
            return 1; //If a1 is higher priority
        }
        else //If the current node is due earlier
        {
            return -1; //If a2 is higher priority
        }
    }
    else if(a1.dueDate.day != a2.dueDate.day)//If they have different days, in the same month
    {
        if(a1.dueDate.day < a2.dueDate.day)
        {
            return 1; //If a1 is higher priority
        }
        else
        {
            return -1; //If a2 is higher priority
        }
    }
    else if(a1.points != a2.points)//If both nodes have the same dueDate
    {
        if(a1.points > a2.points)
        {
            return 1; //If a1 is higher priority
        }
        else
        {
            return -1; //If a2 is higher priority
        }
    }
    else
    {
        return 0; //If they have the same priority
    }

}

void printData(Data d1) //Prints out data
{
    printf("Course name: %s\n",d1.courseName);
    printf("Assignment name: %s\n",d1.assignmentName);
    printf("Points: %d\n",d1.points);
    printf("Duedate: %d/%d\n",d1.dueDate.month,d1.dueDate.day);
}

void display(QueuePtr que) //Prints the whole queue
{
    NodePtr temp = que -> head;
    int count;
    count = 0;
    while(temp != NULL)
    {
        printData(temp -> data);
        printf("\n");
        temp = temp -> next;
        count++;
    }
}

void getData(QueuePtr que, int num) //Gets num amount of data from user input
{
    int i,c;
    Data d1;
    int getPoints,getDay,getMonth;
    char getCourse[50], getAssignment[50];
    for(i = 0; i < num; i++)
    {

            printf("Please type in the name of the course: ");
        gets(getCourse);

        printf("Please type in the name of the assignment: ");
        gets(getAssignment);

        printf("Please type in the amount of points the assignment is worth: ");
        scanf("%d",&getPoints);

        printf("Please type in the month the assignment is due: ");
        scanf("%d",&getMonth);

        printf("Please type in the day the assignment is due: ");
        scanf("%d",&getDay);

        strcpy(d1.courseName,getCourse);
        strcpy(d1.assignmentName,getAssignment);
        d1.points = getPoints;
        d1.dueDate.month = getMonth;
        d1.dueDate.day = getDay;
        enqueue(que,d1);
        printf("\n\n");

        while ( (c = getchar()) != '\n' && c != EOF );

    }
}

