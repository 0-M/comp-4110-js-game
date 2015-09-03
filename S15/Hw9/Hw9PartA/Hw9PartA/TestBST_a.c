#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree_a.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("CoursesTaken_a.txt","r");
    BinTreePtr tree = intBinaryTree();
    char line[100];
    while(fgets(line,100,fp) != NULL)
    {
        printf("Currently being added to the tree: %s",line);
        addBST(&(tree -> root),line);
    }

    printf("\nSearching for Computing II. \n");
    searchTree(tree -> root,"Computing II\n");
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
