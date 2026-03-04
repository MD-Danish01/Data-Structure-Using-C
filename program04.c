/*
Write a C program to implement a stack using arrays with push, pop, peek, and display
operations. Demonstrate stack overflow and underflow scenarios.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

void displayStack(struct Stack *s)
{
    int i = s->top;
    if (i == -1)
    {
        printf("stack is underflow, nothing to display.\n");
        return;
    }
    for (; i >= 0; i--)
    {
        printf("______________\n");
        printf("|______%d_____|\n", s->arr[i]);
    }
}

void isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is underflow.\n");
        exit(1);
    }
}

void isFull(struct Stack *s)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is overflow.\n");
        displayStack(s);
        exit(1);
    }
}

void push(struct Stack *s, int data)
{
    isFull(s);
    s->arr[++s->top] = data;
}

int pop(struct Stack *s)
{
    isEmpty(s);
    printf("pop -> %d\n", s->arr[s->top--]);
    return s->arr[s->top];
}

void peek(struct Stack *s)
{
    isEmpty(s);
    printf(" top element -> %d\n", s->arr[s->top]);
}

int main()
{
    struct Stack s1;
    initStack(&s1);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);

    peek(&s1);

    displayStack(&s1);

    pop(&s1);
    pop(&s1);

    displayStack(&s1);
    peek(&s1);

    return 0;
}