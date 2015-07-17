/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment0xpe0y: ProgramName          */
/*                                                */
/* Approximate completion time: ... minutes       */
/**************************************************/

/*
   This program... (description of what the program does)
*/


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedListPtr initLinkedList()  //Creates a linked list
{

    LinkedListPtr    list;

    if ((list = (LinkedListPtr)malloc(sizeof(LinkedList))) == NULL) //If there isn't enough memory
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    list->head = NULL;
    printf("Linked list has been successfully created.\n");
    return list;
}

void add(LinkedListPtr list, Data data, int position) //Adds a node to the linked list
{
    NodePtr newNode,nodeBefore,nodeAfter;
    int i;
    newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL)
    {
        list->head = newNode;
        printf("list->head->data: %d\n",list->head->data);
    }
    else
    {
        nodeBefore = list->head;
        nodeAfter = NULL;
        for(i = 0; i < position-1; i++)
        {
            nodeBefore = nodeBefore->next;
        }
        if(nodeBefore->next == NULL)
        {
            nodeBefore->next = newNode;
            newNode->next = NULL;
        }
        else
        {
            if(position == 0)
            {
                newNode->next = list->head;
                list->head = newNode;
            }

            else
            {
                nodeBefore = list->head;
                for(i = 0; i < position-2; i++)
                {
                    nodeBefore = nodeBefore->next;
                }
                nodeAfter = nodeBefore->next;

                printf("nodeBefore->data: %d\n",nodeBefore->data);
                printf("nodeAfter->data: %d\n",nodeAfter->data);
                nodeBefore->next = newNode;
                newNode->next = nodeAfter;
            }

        }

    }

}




void insertAtHead(LinkedListPtr list, int data)
{

    NodePtr newNode;
    newNode = (NodePtr)malloc(sizeof(Node));
    /*check that malloc does not return NULL, if yes – output an error and exit */
    if (newNode == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next =NULL;


    /* add it to the beginning of linked list*/
    if  (list->head==NULL) /*linked list is empty*/
        list->head=newNode;
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}

void display(LinkedListPtr list)
{
    NodePtr node = list->head;
    printf("Linked List: ");

    if (list->head == NULL)
        printf("Empty");

    while (node != NULL)
    {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
    printf("\n");
}

Data check(LinkedListPtr list, int position)
{
    NodePtr temp;
    int i;
    temp = list->head;
    for(i = 0; i < position-1; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

void replaceData(LinkedListPtr list, int position, Data data)
{
    NodePtr temp;
    int i;
    temp = list->head;
    for(i = 0; i < position-1; i++)
    {
        temp = temp->next;
    }
    temp->data = data;


}


void removeData(LinkedListPtr list, int position)
{
    NodePtr temp,toRemove;
    int i,count;
    temp = list->head;
    if(position == 0)
    {
        toRemove = list->head;
        list->head = list->head->next;
        toRemove = NULL;
    }
    else
    {
        for(i = 0; i < position-1; i++) //NodeBefore
        {
            temp = temp->next;
            count++;
        }
        toRemove = temp->next;
        temp->next = toRemove->next;
        toRemove = NULL;

    }

    printf("The value at position %d has been removed.\n",position);



}

void emptyList(LinkedListPtr list)
{
    NodePtr findCount;
    int count;
    findCount = list->head;
    while(findCount != NULL)
    {
        findCount = findCount->next;
        count++;
    }

    while(list->head != NULL)
    {
        removeData(list,count-1);
        count--;
    }

    printf("The list has been emptied.\n");
}

int isEmpty(LinkedListPtr list)
{
    if(list->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }





}

LinkedListPtr destroy(LinkedListPtr list)
{
    int emptyCheck;
    emptyCheck = 0;

    emptyCheck = isEmpty(list);

    if(emptyCheck == 1)
    {
        free(list);
        printf("The list has been destroyed.\n");
    }
    return list;
}


