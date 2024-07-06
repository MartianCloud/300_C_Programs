#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list* next;
};

void printList(struct list* node) {
    struct list* n=node;
    while (n != NULL) {
        printf("Data -> %d\n", n->data);
        n = n->next;
    }
}

struct list* addNode() {
    static int listNum = 0;
    int value = 0;
    listNum += 1;
    // printf("Enter the data for node %d\n", listNum);
    // scanf("%d", &value);
    struct list* newNode = (struct list*)malloc(sizeof(struct list));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(void) {
    struct list* a = addNode();
    struct list* b = addNode();
    struct list* c = addNode();

    a->next = b;
    b->next = c;
    c->next = NULL;

    printList(a);
	free(a);
	free(b);
	free(c);

    return 0; 
}
