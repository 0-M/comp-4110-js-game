typedef char *NodeData;

typedef struct node
{
    NodeData data;
    struct node *left;
    struct node *right;
} Node,*NodePtr;

typedef struct tree
{
    NodePtr root;
} BinTree,*BinTreePtr;

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
