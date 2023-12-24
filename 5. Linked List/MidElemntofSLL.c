#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle element of the linked list
int findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1; // Return -1 to indicate an error or no middle element
    }

    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    // Traverse the list with two pointers, one moving twice as fast
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;       // Move slow pointer one step
        fast_ptr = fast_ptr->next->next; // Move fast pointer two steps
    }

    // The slow pointer now points to the middle element
    return slow_ptr->data;
}

// Function to insert a new node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Append elements to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Linked list: ");
    display(head);

    int middle = findMiddle(head);
    if (middle != -1) {
        printf("Middle element: %d\n", middle);
    }

    return 0;
}