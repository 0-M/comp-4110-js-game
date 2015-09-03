typedef struct Data
{
 int courseNumber;
 char courseName[50];
 char semesterTaken[50];
 char instructor[50];
 int liked;
}Data,*DataPtr;

Data* initHashTable(); //allocates space for a hash table
int hashFn(int courseNumber); //returns the location equal to courseNumber
Data* searchHash(Data* hashTable, int courseNumber); //Search the course by the course number calling the hash function
int addHash(Data* hashTable,Data course); //search for the course number calling hash function, if it's found return 0, otherwise put the course data into the hash table and return 1
void displayData(Data data); //displays data
