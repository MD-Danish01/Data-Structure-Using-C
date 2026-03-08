/*
Write a C program to implement a linear queue using arrays with enqueue, dequeue, and
display operations. Include overflow and underflow checks.
*/

#include <stdio.h>
#define MAX 10

struct Queue
{
    int arr[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue *Q, int data)
{
    if (Q->front == -1)
    {
        Q->arr[++Q->rear] = data;
        Q->front++;
    }
    else
    {
        if (Q->rear == MAX - 1)
        {
            printf("Queue is overflow, can not enqueue.\n");
            return;
        }
        Q->arr[++Q->rear] = data;
    }
}

void dequeue(struct Queue *Q)
{
    if (Q->front == -1)
    {
        printf("queue is empty, can not dequeue.\n");
    }
    else
    {
        if (++Q->front > Q->rear)
        {
            printf("queue become empty.\n");
            // reset queue
            Q->front = -1;
            Q->rear = -1;
        }
    }
}

void displayQueue(struct Queue *Q)
{
    int i = Q->front;
    if (i == -1)
    {
        printf("queue is empty, nothing to display.\n");
        return;
    }
    for (; i <= Q->rear; i++)
    {
        printf("%d | ", Q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q1;
    q1.front = -1;
    q1.rear = -1;

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);

    displayQueue(&q1);

    dequeue(&q1);

    displayQueue(&q1);

    dequeue(&q1);
    dequeue(&q1);

    enqueue(&q1, 40);
    enqueue(&q1, 50);
    enqueue(&q1, 60);

    displayQueue(&q1);
    return 0;
}
