#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree_b.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("CoursesTaken_b.txt","r");
    BinTreePtr tree = intBinaryTree();
    int i;
    i = 0;
    NodePtr add = (NodePtr)malloc(sizeof(Node));
    add -> data.key = (char*)malloc(101);
    add -> data.semesterTaken = (char*)malloc(101);
    add -> data.liked = (char*)malloc(101);
    char line[100];
    char delim[2] = "/";
    char hold[3][100],*token;
    while(fgets(line,100,fp) != NULL)
    {
        token = strtok(line,delim);
        while( token != NULL )
        {
            strcpy(hold[i++],token);
            token = strtok(NULL, delim);
        }
        strcpy(add -> data.key,hold[0]);
        strcpy(add -> data.semesterTaken,hold[1]);
        strcpy(add -> data.liked,hold[2]);
        printf("Currently being added to the tree: %s\n",hold[0]);
        addBST(&(tree -> root),&(add -> data));
        i = 0;
    }
    printf("\n\n");

    printf("Searching for Computing II. \n");
    searchTree(tree -> root,"Computing II");
    printf("\n");

    printf("Searching for Computing III. \n");
    searchTree(tree -> root,"Computing III\n");
    printf("\n");


    printf("Sorted tree \n\n");
    inorderTraverse(tree -> root);

    fclose(fp);
    destroyTree(tree);
    return 0;
}
