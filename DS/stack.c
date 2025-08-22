#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX];

int top=-1;

void push(int value){
 if (top==MAX-1)
 {
    printf("Stack overflow\n");
 }
 else
 {
    stack[++top] = value;
 }
}

void pop(){
    if (top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        top--;
        printf("deleted.");
    }
}

void display(){
    if (top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}