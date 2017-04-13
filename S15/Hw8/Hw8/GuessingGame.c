#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

void fillDecisionTree(BinTreePtr tree); //fill a tree with questions and answers
void play(BinTreePtr tree); //plays the guessing game

int main(int argc, char *argv[])
{
    char playAgainC;
    int playAgain;
    playAgain = 0;
    BinTreePtr tree = intBinaryTree();
    fillDecisionTree(tree);
    printf("Number of nodes: %d\n",numNodesSubtree(tree -> root));
    printf("Number of leaves: %d\n",numLeavesSubtree(tree -> root));
    printf("Height of the tree: %d\n",heightSubtree(tree -> root));
    printf("\n");

    while(playAgain == 0)
    {
        play(tree);
        printf("Do you want to play again?(Y or N)");
        playAgainC = getchar();
        if(playAgainC == 'y' || playAgainC == 'Y')
        {
            playAgain = 0;
        }
        else
        {
            playAgain = 1;
        }
        int c;
        while ( (c = getchar()) != '\n' && c != EOF ) { }
    }
    printf("\n");
    destroyTree(tree);



    return 0;
}

void fillDecisionTree(BinTreePtr tree)
{
    addRoot(tree,"Is the animal you're thinking of a pet?(Y or N)");
    addChild(tree -> root,0,"Does the animal you're thinking of usually live in a cage?(Y or N)");
    addChild(tree -> root,1,"If the animal you're thinking of a carnivore?(Y or N)");
    addChild(tree -> root -> left,0,"Does the animal you're thinking of run around on a wheel?(Y or N)");
    addChild(tree -> root -> left,1,"Does the animal you're thinking of need to be walked?(Y or N)");
    addChild(tree -> root -> right,0,"Does the animal you're thinking of have stripes?(Y or N)");
    addChild(tree -> root -> right,1,"Does the animal you're thinking of have a long neck?(Y or N)");
    addChild(tree -> root -> left -> left,0,"The animal you're thinking of is a hamster!");
    addChild(tree -> root -> left -> left,1,"The animal you're thinking of is a rabbit!");
    addChild(tree -> root -> left -> right,0,"The animal you're thinking of is a dog!");
    addChild(tree -> root -> left -> right,1,"The animal you're thinking of is a cat!");
    addChild(tree -> root -> right -> left,0,"The animal you're thinking of is a tiger!");
    addChild(tree -> root -> right -> left,1,"The animal you're thinking of is a lion!");
    addChild(tree -> root -> right -> right,0,"The animal you're thinking of is a giraffe!");
    addChild(tree -> root -> right -> right,1,"The animal you're thinking of is an elephant!");
}

void play(BinTreePtr tree) //plays the guessing game
{
    NodePtr currNode = tree -> root;
    printf("\n");
    printf("Think of one of the following animals: dog,bunny,tiger,giraffe,hamster,lion,cat or elephant\n");
    printf("\n");
    while(!isLeaf(currNode))
    {
        char inputChoice;
        printf("%s",currNode -> data);

        inputChoice = getchar();
        printf("\n");

        int c;
        while ( (c = getchar()) != '\n' && c != EOF ) { }


        if(inputChoice == 'y' || inputChoice == 'Y')
        {
            currNode = currNode -> left;
        }
        else
        {
            currNode = currNode -> right;
        }
    }
    printf("%s",currNode -> data);
    printf("\n");
    printf("\n");

}
