typedef int Data;

typedef struct node{
Data data;
struct node *next;
} Node, *NodePtr;

typedef struct linkedlist{
NodePtr head;
} LinkedList, *LinkedListPtr;

LinkedListPtr initLinkedList();
Data check(LinkedListPtr list, int position);
void replaceData(LinkedListPtr list, int position, Data data);
void display(LinkedListPtr list);
void add(LinkedListPtr list, Data data, int position);
void removeData(LinkedListPtr list, int position);
void emptyList(LinkedListPtr list);
int isEmpty(LinkedListPtr list);
LinkedListPtr destroy(LinkedListPtr list);
void insertAtHead(LinkedListPtr list, int data);
