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
                for(i = 0; i < position-1 ; i++)
                {
                    nodeBefore = nodeBefore->next;
                }
                nodeAfter = nodeBefore->next;
                nodeBefore->next = newNode;
                newNode->next = nodeAfter;
            }

        }

    }

}

void addAfter(LinkedListPtr list, Data data, int position) //Adds a node to the linked list
{
    NodePtr newNode,nodeBefore,nodeAfter;
    int i,pos;
    pos = position + 1;
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
    }
    else
    {
        nodeBefore = list->head;
        nodeAfter = NULL;
        for(i = 0; i < pos-1; i++)
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
            if(pos == 0)
            {
                newNode->next = list->head;
                list->head = newNode;
            }

            else
            {
                nodeBefore = list->head;
                for(i = 0; i < pos-1 ; i++)
                {
                    nodeBefore = nodeBefore->next;
                }
                nodeAfter = nodeBefore->next;
                nodeBefore->next = newNode;
                newNode->next = nodeAfter;
            }

        }

    }

}


void display(LinkedListPtr list,int amount)
{
    NodePtr node = list->head;
    int i ;
    printf("Linked List: ");

    if (list->head == NULL)
        printf("Empty");
//
//    while (node != NULL)
//    {
//        printf("%d, ", node->data);
//        node = node->next;
//    }
    for(i = 0; i < amount; i++)
    {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
    printf("\n");
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




}

void removeDataAfter(LinkedListPtr list, int position)
{
    NodePtr temp,toRemove;
    int i,count;
    temp = list->head;
    if(position == -1)
    {
        toRemove = list->head;
        list->head = list->head->next;
        toRemove = NULL;
    }
    else
    {
        for(i = 0; i < position; i++) //NodeBefore
        {
            temp = temp->next;
            count++;
        }
        toRemove = temp->next;
        temp->next = toRemove->next;
        toRemove = NULL;

    }




}

void removeOutliers(LinkedListPtr list,int outlierValue)
{
    NodePtr temp = NULL;
    NodePtr node = list->head;
    int count;
    count = 0;
    if (list->head == NULL)
        printf("Empty");

    while(node != NULL)
    {
        if(node->data > outlierValue)
        {
            temp = node->next;
            removeData(list,count);
            node = temp;
            count--;
        }
        else
        {
            node = node->next;
        }

        count++;
    }





}


void smoothList(LinkedListPtr list)
{
    int count,toAdd;
    NodePtr p1,p2;
    p1 = list->head;
    p2 = p1->next;
    count = 0;
    if(list->head == NULL || list->head->next == NULL)
    {
        printf("Unable to smooth\n");
    }

    while(p2 != NULL)
    {
        toAdd = (p1->data + p2->data)/2;
        addAfter(list,toAdd,count);
        p1 = p2;
        p2 = p1->next;
        count = count + 2;
    }

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
