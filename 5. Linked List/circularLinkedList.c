
#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list* next;
};

void printList(struct list* node) {
    if(node==NULL)
    {
        printf("Cicular Linked List is empty");
    }

    struct list* currentList=node;
    do
    {
        printf("Data -> %d\n", currentList->data);
        currentList = currentList->next;
    } while (node != currentList);
}

struct list* addNode(int value) {
    struct list* newNode = (struct list*)malloc(sizeof(struct list));
    newNode->data = value;
    return newNode;
}

int main(void) {
    struct list* a = addNode(10);
    struct list* b = addNode(20);
    struct list* c = addNode(30);

    a->next = b;
    b->next = c;
    c->next = a;

    printList(b);
	free(a);
	free(b);
	free(c); 

    return 0; 
}
