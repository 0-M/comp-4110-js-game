#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"



int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("coursesTaken.txt","r");
    Data toAdd,*check;
    int i;
    i = 0;
    char line[100];
    char delim[2] = ",";
    char hold[5][100],*token;
    Data* hashTable = initHashTable();

    while(fgets(line,100,fp) != NULL)
    {
        token = strtok(line,delim);
        while( token != NULL )
        {
            strcpy(hold[i++],token);
            token = strtok(NULL, delim);
        }
        toAdd.courseNumber = atoi(hold[0]);
        strcpy(toAdd.courseName,hold[1]);
        strcpy(toAdd.semesterTaken,hold[2]);
        strcpy(toAdd.instructor,hold[3]);
        toAdd.liked = atoi(hold[4]);
//        printf("CourseNumber: %d\n",toAdd.courseNumber);
//        printf("CourseName: %s\n",toAdd.courseName);
//        printf("SemesterTaken: %s\n",toAdd.semesterTaken);
//        printf("Instructor: %s\n",toAdd.instructor);
//        printf("Liked: %d\n",toAdd.liked);
//        printf("\n");
        addHash(hashTable,toAdd);
        i = 0;
    }

    printf("\n");
    printf("Checking 42102.\n");
    check = searchHash(hashTable,42102);
    if(check != NULL)
    {
        printf("\n");
        displayData(*check);
        check = NULL;
    }

    printf("\n");
    printf("Checking 92125.\n");
    check = searchHash(hashTable,92125);
    if(check != NULL)
    {
        printf("\n");
        displayData(*check);
        check = NULL;
    }

    printf("\n");
    printf("Checking 49201.\n");
    check = searchHash(hashTable,49201);
    if(check != NULL)
    {
        printf("\n");
        displayData(*check);
        check = NULL;
    }

    printf("\n");
    printf("Checking 91104.\n");
    check = searchHash(hashTable,91104);
    if(check != NULL)
    {
        printf("\n");
        displayData(*check);
        check = NULL;
    }


    return 0;
}
