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
    // printf("created succesfully\n");
    // printf("data of created node is:%d", newNode->data);
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

void insertAtBeginning(struct node **head, int value)
{
    struct node *newNode = createNode(value);
    newNode->next = *head;

    *head = newNode;
}

void insertMiddle(struct node **head, int value, int pos)
{
    struct node *newNode = createNode(value);

    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("not psbl");
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertEnd(struct node **head, int value)
{
    struct node *newNode = createNode(value);
    struct node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // *head = newNode;
}

void deleteStart(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted first node successfully.\n");
}

void deleteEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        printf("Deleted last node successfully.\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted last node successfully.\n");
}

void deletePos(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *temp = *head;

    if (pos == 0)
    {
        *head = (*head)->next;
        free(temp);
        printf("Deleted node at position %d successfully.\n", pos);
        return;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Position %d does not exist.\n", pos);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position %d does not exist.\n", pos);
        return;
    }

    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted node at position %d successfully.\n", pos);
}

void searching(struct node *head, int value)
{

    struct node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found in the list at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", value);
}

int main()
{
    struct node *new = createNode(10);
    new->next = createNode(20);
    new->next->next = createNode(30);

    insertAtBeginning(&new, 1000);
    insertMiddle(&new, 2000, 3);
    insertEnd(&new, 3000);

    display(new);

    deleteEnd(&new);
    deletePos(&new, 2);
    deleteStart(&new);

    searching(new, 2000);
}
