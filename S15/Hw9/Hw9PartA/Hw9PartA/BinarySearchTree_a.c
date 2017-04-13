#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree_a.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

int hasLeft(NodePtr node); //If the node has a left child
int hasRight(NodePtr node); //If the node has a right child
int isLeaf(NodePtr node); //If the node is a leaf(has no children)
BinTreePtr intBinaryTree(); //Initializes Binary Tree to an empty tree
NodePtr makeNode(NodeData data); //Allocates the node fills data then returns node.  Can later be assigned to the root pointer or another pointer
int isEmpty(BinTreePtr tree); //Is the tree empty(root == NULL)
NodePtr emptySubtree(NodePtr node); //Recursive function following post-order traversal to free memory
BinTreePtr destroyTree(BinTreePtr tree); //If tree is not empty, then empty it other wise return tree = NULL
int numNodesSubtree(NodePtr node); //Counts the number of nodes in the subtree of node
int numLeavesSubtree(NodePtr node); //Counts the number of leaves in the subtree of node
int heightSubtree(NodePtr node); //Find the height of the subtree of node
void inorderTraverse(NodePtr node); //Does an in-order traversal of the tree
NodePtr searchTree(NodePtr node,NodeData data); //Searches the tree for given data
void addBST(Node **node, NodeData data); //Searches for data if found return NULL otherwise it adds it to the correct spot


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

NodePtr makeNode(NodeData data) //Allocates the node fills data then returns node.  Can later be assigned to the root pointer or another pointer
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np -> data = (char*)malloc(strlen(data) + 1);
    strcpy(np -> data,data);
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

NodePtr emptySubtree(NodePtr node) //Recursive function following post-order traversal to free memory
{
    if(node != NULL)
    {
        emptySubtree(node -> left);
        emptySubtree(node -> right);
        free(node -> data);
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

void inorderTraverse(NodePtr node) //Does an in-order traversal of the tree
{
    if(node != NULL)
    {
        inorderTraverse(node -> left);
        printf("%s\n",node -> data);
        inorderTraverse(node -> right);
    }
}

NodePtr searchTree(NodePtr node,NodeData data) //Searches the tree for given data
{
    if(node == NULL)
    {
        printf("The class you are searching for is not in your list, you have not taken %s\n",data);
        return NULL;
    }
    else
    {
        int comp;
        comp = strcmp(data,node -> data);
        if(comp < 0)
        {
            searchTree(node -> left,data);
        }
        else if(comp > 0)
        {
            searchTree(node -> right,data);
        }
        else
        {
            printf("You have taken %s",data);
            return node;
        }
    }
    return NULL;
}

void addBST(Node **node, NodeData data)  //Searches for data if found return NULL otherwise it adds it to the correct spot
{
    if(*node == NULL)
    {
        *node = makeNode(data);
        return;
    }
    else
    {
        int comp;
        comp = strcmp(data,(*node) -> data);

        if(comp < 0)
        {
            addBST(&(*node) -> left,data);
        }
        else if(comp > 0)
        {
            addBST(&(*node) -> right,data);
        }
    }

}
