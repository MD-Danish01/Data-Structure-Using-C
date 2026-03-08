/*
Write a C program to implement a queue using a linked list and perform all fundamental 
operations with dynamic memory management.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Queue
{
    node *front;
    node *rear;
} queue;

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

void enqueue(queue *, int);

void dequeue(queue *);

void displayQueue(queue *Q)
{
    if (Q->front == NULL)
    {
        printf("queue is empty nothing to display.\n");
        return;
    }
    node *ptr = Q->front;
    while (ptr != NULL)
    {
        printf("%d | ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    queue q1;
    q1.front = NULL;
    q1.rear = NULL;

    enqueue(&q1, 10);
    dequeue(&q1);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);

    displayQueue(&q1);

    enqueue(&q1, 50);
    enqueue(&q1, 60);
    enqueue(&q1, 70);
    enqueue(&q1, 80);

    dequeue(&q1);
    dequeue(&q1);

    displayQueue(&q1);
    return 0;
}

void enqueue(queue *Q, int data)
{
    if (Q->front == NULL)
    {
        Q->front = createNode(data);
        Q->rear = Q->front;
    }
    else
    {
        Q->rear->next = createNode(data);
        Q->rear = Q->rear->next;
    }
}

void dequeue(queue *Q)
{
    if (Q->front == NULL)
    {
        printf("queue is empty, can not dequeue.\n");
        return;
    }
    node *ptr = Q->front;
    if (ptr->next == NULL)
    {
        free(ptr);
        Q->front = NULL;
        Q->rear = NULL;
    }
    else
    {
        Q->front = Q->front->next;
        free(ptr);
    }
}