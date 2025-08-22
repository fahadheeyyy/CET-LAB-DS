#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;
    printf("Enter a value to enqueue: ");
    scanf("%d", &value);
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}
void deque()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty");
    }
    else
    {
        front++;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
    printf("\n");
}
int main()
{

    int choice;

    printf("enter here:\n ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        enqueue();
        break;

    case 2:
        deque();
        break;

    case 3:
        display();
        break;

    default:
        break;
    }

    // enqueue(10);
    // enqueue(20);
    // enqueue(30);
    // display();
    // deque();
    // display();
    return 0;
}