#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtStart(int data , int i){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        return;
    }
    struct Node* last = head->prev;
    newNode->next=head;
    newNode->prev=last;
    last->next=newNode;
    head->prev=newNode;
    if (i==0){
    head=newNode; 
    }
}

// void insertAtPos(int data , int pos){
//     if (pos==1){
//        insertAtStart(data,0);
//        return;
//     }
//     struct Node* temp = head;
//     for (int i = 1 ; i < pos-1 && temp->next!=head;i++){
//         temp=temp->next;
//     }
//     if (temp->next=head){
//         insertAtStart(data , 1);
//         return;
//     }
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data=data;
//     newNode->next=temp->next;
//     newNode->prev=temp;
//     temp->next->prev=newNode;
//     temp->next=newNode;
// }
void insertAtPos(int data, int pos) {
    if (pos == 1) {
        insertAtStart(data,0);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    if (temp->next == head) {
        insertAtStart(data,1);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void display(){
    if (head==NULL){
        printf("LL is empty\n");
        return;
    }
    struct Node* temp=head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    return;
}

int main(){
    insertAtStart(10 , 0);
    insertAtStart(20 ,0);
    insertAtStart(2222 ,1);
    insertAtStart(30,0);
    insertAtPos(40 , 3);
    display();
    return 0;
}