#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at the beginning
void insertAtStart(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

// Insert at the end
void insertAtEnd(int data) {
    if (head == NULL) {
        insertAtStart(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    last->next = newNode;
    newNode->next = head;
}

// Insert at a given position
void insertAtPos(int data, int pos) {
    if (pos == 1) {
        insertAtStart(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        insertAtEnd(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteAtStart() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    struct Node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete last node
void deleteAtEnd() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete at given position
void deleteAtPos(int pos) {
    if (head == NULL) return;

    if (pos == 1) {
        deleteAtStart();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) return; // invalid pos

    prev->next = temp->next;
    free(temp);
}

// Search
int search(int key) {
    if (head == NULL) return -1;

    struct Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

// Display
void display() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Main
int main() {
    insertAtStart(10);
    insertAtEnd(20);
    insertAtPos(15, 2);
    
    display();

    deleteAtPos(2);
    display();

    int pos = search(20);
    printf("Found at position: %d\n", pos);

    return 0;
}
