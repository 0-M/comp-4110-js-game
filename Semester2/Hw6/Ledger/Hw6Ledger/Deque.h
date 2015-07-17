typedef struct Data
{
    char *nameOfStock;
    int numberOfShares;
    double PurchaseCostPerShare;
    double CurrentPricePerShare;
} Data,*DataPtr;



typedef struct node
{
    Data data;
    struct node *next;
    struct node *prev;
} Node, *NodePtr;

typedef struct dequeue
{
    NodePtr head;
    NodePtr tail;
} Deque, *DequePtr;


DequePtr initDeque(); //Initialize the queue
void destroyDeque(DequePtr deq); //Destroy the queue
int isEmpty(DequePtr deq); //Check is the queue is empty
void emptyDeq(DequePtr deq); //Empties the queue
Data getFront(DequePtr deq); //Returns the front element in the queue
Data getBack(DequePtr deq); //Returns the back element in the queue
void addFront(DequePtr deq,Data d); //Adds an element to the front of the queue
void addBack(DequePtr deq,Data d); //Adds an element to the back of the queue
Data removeFront(DequePtr deq); //Removes and returns the front element of the queue
Data removeBack(DequePtr deq); //Removes and returns the last element of the queue

