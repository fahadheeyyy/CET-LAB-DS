#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if (q->rear==NULL){
        q->rear=q->front=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
}

void dequeue(struct Queue* q){
    if(q->front==NULL){
    printf("queue is empty\n");
    return;
   }
   struct Node* temp = q->front;
   q->front = q->front->next;
   free(temp);
   return;
}


void display(struct Queue* q){
   if(q->front==NULL){
    printf("queue is empty\n");
    return;
   }
   struct Node* temp = q->front;
   while (temp != NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
   }
   printf("\n");
}

int main(){
    struct Queue* q = createQueue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    display(q);
    dequeue(q);
    display(q);
}
