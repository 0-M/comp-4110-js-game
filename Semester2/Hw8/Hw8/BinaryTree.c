#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

int hasLeft(NodePtr node); //If the node has a left child
int hasRight(NodePtr node); //If the node has a right child
int isLeaf(NodePtr node); //If the node is a leaf(has no children)
BinTreePtr intBinaryTree(); //Initializes Binary Tree to an empty tree
NodePtr makeNode(NodeData Ndata); //Allocates the node fills data then returns node.  Can later be assigned to the root pointer or another pointer
int isEmpty(BinTreePtr tree); //Is the tree empty(root == NULL)
NodePtr addRoot(BinTreePtr tree,NodeData Ndata); //Makes a new node and sets it equal to the root
NodePtr addChild(NodePtr parent,int leftOrRightChild,NodeData Ndata); //Makes a new node set to left or right of the parent
NodePtr emptySubtree(NodePtr node); //Recursive function following post-order traversal to free memory
BinTreePtr destroyTree(BinTreePtr tree); //If tree is not empty, then empty it other wise return tree = NULL
int numNodesSubtree(NodePtr node);
int numLeavesSubtree(NodePtr node);
int heightSubtree(NodePtr node);

int hasLeft(NodePtr node) //If the node has a left child
{
    if(node -> left == NULL) //no left child
    {
        return 0;
    }
    else //has left child
    {
        return 1;
    }
}

int hasRight(NodePtr node) //If the node has a left child
{
    if(node -> right == NULL) //no left child
    {
        return 0;
    }
    else //has left child
    {
        return 1;
    }
}

int isLeaf(NodePtr node) //If the node is a leaf(has no children)
{
    if(hasRight(node) || hasLeft(node))//If the node has a left or a right it is not a leaf
    {
        return 0;
    }
    else //IF the node doesn't have a left or a right it's a leaf
    {
        return 1;
    }
}
BinTreePtr intBinaryTree() //Initializes Binary Tree to an empty tree
{
    BinTreePtr bp = (BinTreePtr)malloc(sizeof(BinTree));
    bp -> root = NULL;
    return bp;
}

NodePtr makeNode(NodeData Ndata) //Allocates the node fills data then returns node.  Can later be assigned to the root pointer or another pointer
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    //printf("NDATA: %s\n",Ndata);
    strcpy(np -> data,Ndata);
    np -> left = NULL;
    np -> right = NULL;
    return np;
}

int isEmpty(BinTreePtr tree) //Is the tree empty(root == NULL)
{
    if(tree -> root == NULL)//If the tree is empty
    {
        return 1;
    }
    else //If the tree is empty
    {
        return 0;
    }
}

NodePtr addRoot(BinTreePtr tree,NodeData Ndata) //Makes a new node and sets it equal to the root
{
    // printf("NDATA1: %s\n",Ndata);
    if(isEmpty(tree))
    {
        tree -> root = makeNode(Ndata);
        return tree -> root;
    }
    else
    {
        return NULL;
    }
}

NodePtr addChild(NodePtr parent,int leftOrRightChild,NodeData Ndata) //Makes a new node set to left or right of the parent
{
    Node *child = makeNode(Ndata);
    if(leftOrRightChild == 0) //If adding to left
    {
        parent -> left = child;
    }
    else //If adding to right
    {
        parent -> right = child;
    }

    return child;
}

NodePtr emptySubtree(NodePtr node) //Recursive function following post-order traversal to free memory
{
    if(node != NULL)
    {
        emptySubtree(node -> left);
        emptySubtree(node -> right);
        free(node);
    }
    return node = NULL;
}

BinTreePtr destroyTree(BinTreePtr tree) //If tree is not empty, then empty it otherwise return tree = NULL
{
    if(!isEmpty(tree))
    {
        tree -> root = emptySubtree(tree -> root);
        printf("The tree has been emptied.\n");
    }
    free(tree);
    tree = NULL;
    printf("The tree has been destroyed.\n");
    return tree;
}

int numNodesSubtree(NodePtr node)
{
    if(node == NULL) //Base case (no more nodes)
    {
        return 0;
    }
    return 1 + numNodesSubtree(node -> left) + numNodesSubtree(node -> right);
}

int numLeavesSubtree(NodePtr node)
{
    if(node == NULL) //Base case (no more nodes)
    {
        return 0;
    }
    if(node -> left == NULL && node -> right == NULL) //If the node has no children
    {
        return 1;
    }
    return numLeavesSubtree(node -> left) + numLeavesSubtree(node -> right); //Search left and search right
}

int heightSubtree(NodePtr node)
{
    if(node == NULL) //Base case (no more nodes)
    {
        return 0;
    }
    return  1 + max(heightSubtree(node -> left),heightSubtree(node -> right));


}
