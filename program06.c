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
        // Check for circular overflow: if next position of rear equals front
        if ((Q->rear + 1) % MAX == Q->front)
        {
            printf("Queue is overflow, can not enqueue.\n");
            return;
        }
        Q->rear = (Q->rear + 1) % MAX;
        Q->arr[Q->rear] = data;
    }
}

void dequeue(struct Queue *Q)
{
    if (Q->front == -1)
    {
        printf("queue is empty, can not dequeue.\n");
        return;
    }
    // Check if only one element before dequeue
    if (Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
        return;
    }
    Q->front = (Q->front + 1) % MAX;
}


void displayQueue(struct Queue *Q)
{
    int i = Q->front;
    if (i == -1)
    {
        printf("queue is empty, nothing to display.\n");
        return;
    }
    while (i != Q->rear)
    {
        printf("%d | ", Q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", Q->arr[Q->rear]);
}

int main()
{
    struct Queue q1;
    q1.front = -1;
    q1.rear = -1;

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    enqueue(&q1, 50);
    enqueue(&q1, 60);
    enqueue(&q1, 70);
    enqueue(&q1, 80);

    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);

    displayQueue(&q1);

    enqueue(&q1, 90);
    enqueue(&q1, 100);
    enqueue(&q1, 110);
    enqueue(&q1, 120);

    displayQueue(&q1);

    enqueue(&q1, 130);
    enqueue(&q1, 140);

    displayQueue(&q1);

    enqueue(&q1, 150);

    return 0;
}
