#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

struct node *mList(struct node *list1, struct node *list2)
{
    struct node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;

    // display(mList);
    return list1;
}

int main()
{

    struct node *new1 = createNode(10);
    new1->next = createNode(30);
    new1->next->next = createNode(40);

    struct node *new2 = createNode(10);
    new2->next = createNode(30);
    new2->next->next = createNode(40);

    printf("list 1:\n");
    display(new1);
    printf("list 2:\n");
    display(new2);

    struct node *merged = mList(new1, new2);
    printf("after merging:\n");
    display(merged);
}