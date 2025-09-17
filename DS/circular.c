#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtStart(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    if (head == NULL) {
        insertAtStart(data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtStart() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* last = head->prev;
    struct Node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* last = head->prev;
    struct Node* newLast = last->prev;
    newLast->next = head;
    head->prev = newLast;
    free(last);
}

void deleteAtPos(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteAtStart();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;
    if (temp == head) return;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

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

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

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
