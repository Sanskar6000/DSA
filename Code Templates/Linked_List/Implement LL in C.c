#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Define a structure for the linked list
typedef struct LinkedList {
    Node* head;
    Node* curr;
} LinkedList;

// Function to create a new node with the given data
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to initialize the linked list
void initializeLinkedList(LinkedList* ll) {
    ll->head = NULL;
    ll->curr = NULL;
}

// Function to insert a node with data at the end of the linked list
void insertNode(LinkedList* ll, int data) {
    if (ll->head == NULL) {
        ll->head = newNode(data);
        ll->curr = ll->head;
    } else {
        ll->curr->next = newNode(data);
        ll->curr = ll->curr->next;
    }
}

// Function to print the linked list
void printList(LinkedList* ll) {
    Node* temp = ll->head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(LinkedList* ll) {
    if (ll->head == NULL) return;

    Node* prev = NULL;
    Node* curr = ll->head;
    Node* nxt = ll->head->next;

    while (nxt != NULL) {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }

    curr->next = prev;
    ll->head = curr;
}

int main() {
    LinkedList ll;
    
    initializeLinkedList(&ll);
    
    insertNode(&ll, 5);
    insertNode(&ll, 6);
    insertNode(&ll, 7);
    insertNode(&ll, 8);
    
    printList(&ll);
    printf("\n");
    reverseList(&ll);
    
    printList(&ll);

    // Free the memory used by the linked list
    Node* current = ll.head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
