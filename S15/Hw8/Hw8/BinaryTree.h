typedef char NodeData[101];

typedef struct node
{
    NodeData data;
    struct node *left;
    struct node *right;
}Node,*NodePtr;

typedef struct tree
{
    NodePtr root;
}BinTree,*BinTreePtr;

int hasLeft(NodePtr node); //If the node has a left child
int hasRight(NodePtr node); //If the node has a right child
int isLeaf(NodePtr node); //If the node is a leaf(has no children)
BinTreePtr intBinaryTree(); //Initializes Binary Tree to an empty tree
NodePtr makeNode(NodeData data); //Allocates the node fills data then returns node.  Can later be assigned to the root pointer or another pointer
int isEmpty(BinTreePtr tree); //Is the tree empty(root == NULL)
NodePtr addRoot(BinTreePtr tree,NodeData data); //Makes a new node and sets it equal to the root
NodePtr addChild(NodePtr parent,int leftOrRightChild,NodeData data); //Makes a new node set to left or right of the parent
NodePtr emptySubtree(NodePtr node); //Recursive function following post-order traversal to free memory
BinTreePtr destroyTree(BinTreePtr tree); //If tree is not empty, then empty it other wise return tree = NULL
int numNodesSubtree(NodePtr node);
int numLeavesSubtree(NodePtr node);
int heightSubtree(NodePtr node);
