#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

Data* initHashTable(); //allocates space for a hash table
int hashFn(int courseNumber); //returns the location equal to courseNumber
Data* searchHash(Data* hashTable, int courseNumber); //Search the course by the course number calling the hash function
int addHash(Data* hashTable,Data course); //search for the course number calling hash function, if it's found return 0, otherwise put the course data into the hash table and return 1
void displayData(Data data); //displays data

Data* initHashTable() //allocates space for a hash table
{
    Data* data = (DataPtr)malloc(100000 * sizeof(Data));
    return data;
}

int hashFn(int courseNumber) //returns the location equal to courseNumber
{
   return courseNumber;
}

Data* searchHash(Data* hashTable, int courseNumber) //Search the course by the course number calling the hash function
{
    int hashNum;
    hashNum = -1;
    hashNum = hashFn(courseNumber);
    if(hashTable[hashNum].courseNumber == 0)
    {
        printf("The course has not been found.\n");
        return NULL;
    }
    else
    {
        printf("The course has been found.\n");
        return &(hashTable[hashNum]);
    }
}

int addHash(Data* hashTable,Data course) //search for the course number calling hash function, if it's found return 0, otherwise put the course data into the hash table and return 1
{
    int hashNum;
    hashNum = -1;
    hashNum = hashFn(course.courseNumber);
    if(hashTable[hashNum].courseNumber != 0)
    {
        return 0;
    }
    else
    {
        hashTable[hashNum] = course;
        return 1;
    }


}

void displayData(Data data) //displays data
{
   printf("Course number: %d\n",data.courseNumber);
   printf("Course name: %s\n",data.courseName);
   printf("Semester taken: %s\n",data.semesterTaken);
   printf("Instructor: %s\n",data.instructor);
   if(data.liked == 1)
   {
       printf("Liked: Yes\n");
   }
   else
   {
       printf("Liked: No\n");
   }
}
