/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment01: ToDoList                 */
/*                                                */
/* Approximate completion time: ... minutes       */
/**************************************************/

/*
   This program reads in a to do list from an input file, does various
   operations on that list and puts the final list to an output file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayAtLoc(char *arr[],int numOfTasks);
void displayAll(char *arr[],int numOfTasks);
void replaceTask(char *arr[],int numOfTasks,int maxTaskLength);
void removeTask(char *arr[],int numOfTasks);
char ** addTask(char *arr[],int *numOfTasks,int *sizeOfArray,int maxTaskLength);
void moveTask(char *arr[],int numOfTasks,int sizeOfArray,int fromLoc,int toLoc,int maxTaskLength);


int main(int argc, char *argv[])
{
    int maxTaskLength,sizeOfArray,numOfTasks,i,count,menuChoice,fromLoc,toLoc;
    char **taskList,lineHolder[30];
    maxTaskLength = 30; //Maximum number of chars to be read per line
    sizeOfArray = 0;//space in the array
    numOfTasks = 0; //number of tasks
    count = 0;
    menuChoice = 0; //what option in the menu the user selects
    fromLoc = -1;
    toLoc = -1;
    FILE *input_file,*output_file; //Open input file
    input_file = fopen("original_list.txt","r");
    output_file = fopen("final_list.txt","w");
    //input_file2 = fopen("original_list.txt","r");
    while(fgets(lineHolder,maxTaskLength,input_file) != NULL)
    {
        sizeOfArray++;
    }

    numOfTasks = sizeOfArray;
    taskList = malloc(sizeOfArray * sizeof(char*)); //Malloc the array
    rewind(input_file);

    for(i = 0; i < sizeOfArray; i++)
    {
        taskList[i] = malloc(maxTaskLength * sizeof(char));
    }
    while(fgets(taskList[count],maxTaskLength,input_file) != NULL)
    {
        count++;
    }
    strcat(taskList[numOfTasks-1],"\n");
    do
    {
        printf("\n");
        printf("1. Display an item at a given location\n");
        printf("2. Display all items\n");
        printf("3. Replace a task at a given location\n");
        printf("4. Add a task at a given location\n");
        printf("5. Remove a task at a given location\n");
        printf("6. Move a task to another location\n");
        printf("7. Quit\n\n");
        scanf("%d",&menuChoice); /* Get input */

        switch(menuChoice)
        {

        case 1  :
            displayAtLoc((char **)taskList,numOfTasks);
            break; /* optional */

        case 2  :
            displayAll((char **)taskList,numOfTasks);
            break; /* optional */

        case 3  :
            replaceTask((char **)taskList,numOfTasks,maxTaskLength);
            break; /* optional */

        case 4  :
                if(numOfTasks == sizeOfArray)
            {
                sizeOfArray++;
            }
            numOfTasks++;
            taskList = addTask((char **)taskList,&numOfTasks,&sizeOfArray,maxTaskLength);
            break; /* optional */

        case 5  :
          if(numOfTasks == 0)
            {
                printf("A removal could not be done because there are no tasks.\n");
            }
            else
            {
                removeTask((char **)taskList,numOfTasks);
                numOfTasks--;
            }
            break; /* optional */

        case 6  :
                do
            {
        printf("Which task would you like to move?  ");
        scanf("%d",&fromLoc);
            }
        while(fromLoc > numOfTasks || fromLoc < 1);
                   do
            {
        printf("Where would you like to move it?  ");
        scanf("%d",&toLoc);
            }
        while(toLoc > numOfTasks || toLoc < 1);
        moveTask((char **)taskList,numOfTasks,sizeOfArray,fromLoc,toLoc,maxTaskLength);
            break; /* optional */

        case 7  :
            for(i = 0;i < numOfTasks;i++)
            {
                fputs(taskList[i],output_file);
            }
                fclose(input_file);
                fclose(output_file);

                for(i = 0;i < sizeOfArray;i++)
            {
                free(taskList[i]);
            }
                free(taskList);
            break; /* optional */

        default :

            printf("Invalid choice, please try again.\n");
        }





    }
    while(menuChoice != 7);








    return 0;
}







void displayAtLoc(char *arr[],int numOfTasks) //Menu choice 1
{
    int loc;
    loc = -1;
    do
    {
        printf("Which task would you like to display?  ");
        scanf("%d",&loc);
    }
    while(loc > numOfTasks || loc < 0);

    printf("The task at posistion %d is: %s\n",loc,arr[loc - 1]);
}


void displayAll(char *arr[],int numOfTasks) //Menu choice 2
{
    int i;
    printf("\n");
    for(i = 0; i < numOfTasks; i++)
    {
        printf("%d. %s\n",i+1,arr[i]);
    }
    printf("\n");


}

void replaceTask(char *arr[],int numOfTasks,int maxTaskLength)//Menu choice 3
{
    int loc;
    char replace[maxTaskLength];
    //printf("MAX TASK LENGTH: %d\n",maxTaskLength);
    loc = -1;
    do
    {
        printf("Which task would you like to replace?  ");
        scanf("%d",&loc);
    }
    while(loc > numOfTasks || loc < 1);

    printf("What would you like to replace the task at posistion %d with?  ",loc);
    while ( getchar() != '\n');
    {
        fgets (replace,maxTaskLength, stdin);
    }
    strcpy(arr[loc-1],replace);
    printf("Replace successful.\n");

}


void removeTask(char *arr[],int numOfTasks)
{
    int loc,i;
    loc = -1;
    do
    {
        printf("Which task would you like to remove?  ");
        scanf("%d",&loc);
    }
    while(loc > numOfTasks || loc < 1);
    printf("\n");
    printf("Successfully removed task %d: %s\n",loc,arr[loc-1]);

    for(i = loc;i < numOfTasks;i++)
    {
        arr[i-1] = arr[i];
    }

}

char ** addTask(char *arr[],int *numOfTasks,int *sizeOfArray,int maxTaskLength)//Somethings wrong, get a piece of paper out and think about it
{
    int loc;
    loc = -1;
    char add[maxTaskLength];
    do
    {
        printf("Which number would you like your new task to be?  ");
        scanf("%d",&loc);
    }
    while(loc > *numOfTasks || loc < 1);

    printf("What would you like your new task to be?  ");
    while ( getchar() != '\n');
    {
        fgets (add,maxTaskLength, stdin);
    }

    if(*numOfTasks == *sizeOfArray)
    {
        arr = (char **)realloc(arr,((*sizeOfArray) * sizeof(char*)));
        arr[*sizeOfArray-1] = malloc(maxTaskLength * sizeof(char));
    }
        strcpy(arr[*sizeOfArray-1],add);

        moveTask((char **)arr,*numOfTasks,*sizeOfArray,*sizeOfArray,loc,maxTaskLength);
    return (char**)arr;
 }


void moveTask(char *arr[],int numOfTasks,int sizeOfArray,int fromLoc,int toLoc,int maxTaskLength)
{
    int i;
    char temp[maxTaskLength];

    if(fromLoc - toLoc < 0)
    {
        for(i = fromLoc;i < toLoc;i++)
        {
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[i-1]);
        strcpy(arr[i-1],temp);
        }
    }
    else
    {
        for(i = fromLoc;i > toLoc;i--)
        {
            strcpy(temp,arr[i-1]);
            strcpy(arr[i-1],arr[i-2]);
            strcpy(arr[i-2],temp);
        }

    }







}



