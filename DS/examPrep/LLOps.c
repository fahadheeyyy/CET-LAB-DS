#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head , *temp , *current;

void insertFront(){
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
   int data;
   printf("enter the value to be inserted : ");
   scanf("%d",&data);

   if (head==NULL){
      head=newNode;
      newNode->next=NULL;
   }
   else{
    newNode->next=head;
    head=newNode;
   }
   newNode->data=data;
}

void insertEnd(){
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
   int data;
   printf("enter the value to be inserted : ");
   scanf("%d",&data);

   temp=head;

   while(temp->next!=NULL){
    temp=temp->next;
   }
   newNode->next=NULL;
   temp->next=newNode;
   newNode->data=data;
}

void insertPos(){
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
   int data , pos=0;
   printf("enter the value to be inserted : ");
   scanf("%d",&data);
   printf("enter the position to be inserted : ");
   scanf("%d",&pos);

   int i=0;

   temp=head;

   while(i<pos){
    temp=temp->next;
    i=i+1;
   }
   newNode->next=temp->next;
   temp->next=newNode;
   newNode->data=data;
}

void deleteFront(){
    if(head==NULL){
        printf("list is empty");
    }
    else{
    temp=head;
    head=head->next;
    free(temp);
    }
}

void deleteEnd(){
    if(head==NULL){
        printf("list is empty");
    }
    else{
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    current=temp->next;
    temp->next=NULL;
    free(current);
    }
}

void deletePos(){
    int pos , i=0;
    printf("Enter the position :");
    scanf("%d",&pos);
    temp=head;
    while(i<pos){
        temp=temp->next;
        i=i+1;
    }
    current=temp->next;
    temp->next=temp->next->next;
    free(current);
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main(){

    int ch , c=1;

    while (c==1){
        printf("Enter your choice : \n 1.insert at front \n 2.display \n 3.insert at end \n 4.insert at pos \n 5.delete at start \n 6.delete at end \n 7.delete from pos \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insertFront();
            break;
            case 2:
            display();
            break;
            case 3:
            insertEnd();
            break;
            case 4:
            insertPos();
            break;
            case 5:
            deleteFront();
            break;
            case 6:
            deleteEnd();
            break;
            case 7:
            deletePos();
            break;
            default:
            break;
        }

        printf("\ndo you want to continue? 0(no)/1(yes)");
        scanf("%d",&c);
    }
    return 0;
}