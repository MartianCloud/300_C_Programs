#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* addNode(int val){
    struct Node* n1=(struct Node*)(malloc(sizeof(struct Node)));
    n1->data=val;
    n1->prev=NULL;
    n1->next=NULL;
    return n1;
}

void printForward(struct Node* head)
{
    printf("Printing Forward\n");
    while(head!=NULL)
    {
        printf("data ->%d\n",head->data);
        head=head->next;
    }
}

void printBackward(struct Node* Tail)
{
    printf("Printing backward\n");
    while(Tail!=NULL)
    {
        printf("data ->%d\n",Tail->data);
        Tail=Tail->prev;
    }
}

int main(){

    struct Node* N1=addNode(10);
    struct Node* N2=addNode(20);
    struct Node* N3=addNode(30);
    struct Node* N4=addNode(40);

    N1->prev=NULL;
    N1->next=N2;
    N2->prev=N1;
    N2->next=N3;
    N3->prev=N2;
    N3->next=N4;
    N4->prev=N3;
    N4->next=NULL;

    printBackward(N4);
    printForward(N1);
    
    return 1;
}