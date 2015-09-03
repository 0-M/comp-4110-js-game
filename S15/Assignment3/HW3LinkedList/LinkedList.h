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
void display(LinkedListPtr list,int amount);
void add(LinkedListPtr list, Data data, int position);
void addAfter(LinkedListPtr list, Data data, int position);
void removeData(LinkedListPtr list, int position);
void removeDataAfter(LinkedListPtr list, int position);
void removeOutliers(LinkedListPtr list,int outlierValue);
void smoothList(LinkedListPtr list);
