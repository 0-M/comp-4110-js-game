/*****************************************************/
/* Skeleton provided by S. Bassil (Fall 2014)        */
/*                                                   */
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program: assignment10                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   This program builds a linked list and
   traverses it iteratively and recursively.
*/

#include <stdio.h>
#include <stdlib.h>

/* declaration of structure */
typedef struct node{
	int data;
	struct node *next;
} NODE;
/* declaration of functions */
NODE* insert_node(NODE *ptr, NODE *new);
NODE* find_node(NODE *ptr, int n);
NODE* delete_node(NODE *ptr, int n, int *success_flag_ptr);
void print_backward_iteration(NODE *ptr);
void print_backward_recursion(NODE *ptr);



int main(int argc, char *argv[])
{
    int choice,choice2,success,*z; /* Declaration */

    NODE *start,*new; /* Declaration */
    z = &success; /* Initialization */
    start = NULL; /* Initialization */


    do /* Prompting the user */
    {
        printf("1  Insert integer into linked list\n");
        printf("2  Find integer in linked list\n");
        printf("3  Delete integer from linked list\n");
        printf("4  Print out integers backwards using iterative strategy\n");
        printf("5  Print out integers backwards using the recursive strategy\n");
        printf("6  Quit\n");
        printf("Enter 1,2,3,4,5, or 6: ");
        scanf("%d",&choice); /* Get input */


        switch(choice){ /* Handle the user input */
          case 1 :
            printf("Input an integer: ");
            scanf("%d",&choice2); /* Get more user input */
            new = (struct node *)malloc(sizeof(struct node)); /* Dynamically allocates a new node */
            start = insert_node(start,new); /* Set the start pointer to the new node */
            (*start).data = choice2; /* Set the data value of the new node to the user input */
            printf("\n");
            break;


          case 2 :
            printf("Input an integer: ");
            scanf("%d",&choice2); /* Get more user in put */
            if(find_node(start,choice2) == NULL) /* Make a call to a function */
            {
                printf("The integer %d was not found in the linked list.\n",choice2); /* If the integer isn't in the linked list */
            }
            else
            {
                printf("The integer %d was found in the linked list.\n",choice2); /* If the integer is in the linked list */
            }
            printf("\n");
            break;


          case 3 :
            printf("Input an integer: ");
            scanf("%d",&choice2); /* Get more user input */
            success = 0; /* Initialization */
            delete_node(start,choice2,z); /* Make a call to a function */
            if(success == 0) /* If the integer is not found in the list */
            {
              printf("Integer not found.\n");
              printf("No nodes were deleted.\n");
            }
            else /* If it is found */
            {
              printf("The node containing %d was successfully deleted.\n",choice2);
            }
            printf("\n");
            break;


          case 4 :


            printf("\n");
            print_backward_iteration(start); /* Call to a function */
            break;


          case 5 :


            printf("\n");
            print_backward_recursion(start);
            printf("\n");
            break;


          case 6 :

          printf("\nThank you!");
            break;

          default :
            printf("Invalid choice. Retry.\n\n");
        }

    }while(choice != 6);


	return 0;
}

/* definition of function insert_node */
NODE* insert_node(NODE *ptr, NODE *new)
{
    new->next = ptr; /* The new node points to the current first node */
    return new; /* Return a pointer to the new node */
}

/* definition of function find_node */
NODE* find_node(NODE *ptr, int n)
{
    NODE *curr; /* Declaration */
    int ctr,found; /* Declaration */
    ctr = 0;  /* Initialization */
    found = 0; /* Initialization */
    curr = ptr; /* Initialization */

    while(curr != NULL && found == 0)
    {
        if((*curr).data == n) /* If the current nodes data value is the one being looked for */
        {
            found = 1;/* change a found variable */
        }
        else
        {
            curr = curr->next;
            ctr++;
        }
    }

    if(found == 0) /* If found */
    {
        return NULL;
    }
    else /* If not found */
    {
        return curr;
    }


}

/* definition of function delete_node */
NODE* delete_node(NODE *ptr, int n, int *success_flag_ptr)
{
    NODE *toDel,*prev,*post,*curr; /* Declaration */
    int found; /* Declaration */
    found = 0; /* Initialization */
    toDel = find_node(ptr,n); /* Make a call to the find node function */
    if(toDel != NULL)
    {
        curr = ptr;
        post = toDel->next;
    }

    /* printf("post: %d\n\n",(*post).data); */

    if(toDel == NULL) /* If the node to delete can't be found */
    {
        *success_flag_ptr = 0;
        return ptr;
    }
    else if(toDel == ptr) /* If the node to delete is found, but list is one element long */
    {
        ptr = ptr->next;
        *success_flag_ptr = 1;
        return ptr;
        free(toDel);
    }
    else /* if list is longer than one element */
    {
        while(found == 0)
        {
            if(curr->next == toDel)
            {
                found = 1;
                prev = curr;
                curr = curr ->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        prev->next = post;
        free(toDel);
        *success_flag_ptr = 1;
        return ptr;
    }



}

/* definition of function print_backward_iteration */
void print_backward_iteration(NODE *ptr)
{
   NODE *last,*prev,*curr; /* Declaration */
   int found,empty; /* Declaration */
   curr = ptr; /* Initialization */
   last = NULL; /* Initialization */
   prev = NULL; /* Initialization */
   if(curr == NULL)
   {
       empty = 0;
   }
   else
   {
       empty = 1;
   }

   found = 0;
    /* printf("toDel: %d\n",(*curr).data); */
   while(found == 0 && empty == 1)
   {
          if(curr->next == NULL) /* Only one element in the list */
     {
         last = curr;
         printf("last: %d\n",(*last).data);
         found = 1;
     }
    else if (curr->next->next == NULL)
    {
        prev = curr;
        last = curr->next;
        found = 1;
    }
    else
     {
       curr = curr->next;
     }

   }

   if(prev == NULL && empty == 1)
   {
       printf("Reversed list:\n");
       printf("%d\n\n",(*last).data);

   }
   else if(empty == 0)
   {
       printf("The list is empty.\n\n");
   }
   else
   {
       curr = ptr;
       printf("Reversed list:\n");
       while(last != ptr)
       {
             if(curr->next == last)
             {
                printf("%d ",(*last).data);
                last = curr;
                curr = ptr;
             }
             else
             {
                curr = curr->next;
             }

       }
       printf("%d ",(*ptr).data);
       printf("\n");
   }





}

/* definition of function print_backward_recursion */
/* This function works because once it hits the base case it will start working backwards, it won't
   print anything out until the base case is met and there for once it does start printing out, it will start with the last element
   Got help from this video: https://www.youtube.com/watch?v=K7J3nCeRC80    */
void print_backward_recursion(NODE *ptr)
{
    int done;
    done = 0;
    if(ptr == NULL) /* Base case */
    {
        done = 1; /* When the base case is hit, nothing is returned but it will cause all the print statements to be hit, in reverse order */
    }
    if(done == 0)
    {
         print_backward_recursion(ptr->next); /* Does the next entry in the linked list until the base case is met */
         printf("%d ",(*ptr).data); /* Prints out the entry */
    }
}
