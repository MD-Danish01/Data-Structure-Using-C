/*
Write a C program to implement a stack using a linked list and perform all fundamental
operations with dynamic memory management.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Stack
{
    node *top;
    node *base;
} stack;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory allocation faild.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(stack *S, int data)
{
    if (S->base == NULL)
    {
        S->base = createNode(data);
        S->top = S->base;
    }
    else
    {
        S->top->next = createNode(data);
        S->top = S->top->next;
    }
}

void pop(stack *S)
{
    if (S->base == NULL)
    {
        printf("stack is empty, can not pop.\n");
        return;
    }
    if (S->base == S->top)
    {
        printf("poped -> %d\n", S->base->data);
        free(S->base);
        S->base = NULL;
        S->top = NULL;
        return;
    }
    node *ptr = S->base;
    while (ptr->next != S->top)
    {
        ptr = ptr->next;
    }
    printf("poped -> %d\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
    S->top = ptr;
}

void peek(stack *S)
{
    if (S->base == NULL)
    {
        printf("stack is empty, can not peek\n");
    }
    else
    {
        printf("top element -> %d\n", S->top->data);
    }
}

void dispplayStack(stack *S)
{
    if (S->base == NULL)
    {
        printf("stack is empty nothing to display.\n");
        return;
    }
    node *ptr = S->base;
    printf("| base | ");
    while (ptr != NULL)
    {
        printf("|  %d  | ", ptr->data);
        ptr = ptr->next;
    }
    printf("| top | ");
    printf("\n");
}

int main()
{
    stack s1;
    s1.base = NULL;
    s1.top = NULL;

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    push(&s1, 50);
    push(&s1, 60);

    peek(&s1);

    dispplayStack(&s1);

    pop(&s1);
    pop(&s1);
    pop(&s1);
    peek(&s1);

    dispplayStack(&s1);

    push(&s1, 70);
    push(&s1, 80);
    push(&s1, 90);

    peek(&s1);

    dispplayStack(&s1);
    return 0;
}