/*
Write a C program to implement a doubly linked list using structures, with functionalities 
for insertion, deletion (at beginning, end, and specific position), and traversal. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *pre;
    struct node *next;
} node;

typedef struct List
{
    node *head;
    node *tail;
} list;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("memory allocation failed.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = NULL;
    return newnode;
}

void pushFrunt(list *list, int data)
{
    if (list->head == NULL)
    {
        list->head = createNode(data);
        list->tail = list->head;
    }
    else
    {
        (list->head)->pre = createNode(data);
        ((list->head)->pre)->next = list->head;
        list->head = (list->head)->pre;
    }
}

void pushBack(list *list, int data)
{
    if (list->head == NULL)
    {
        list->head = createNode(data);
        list->tail = list->head;
    }
    else
    {

        (list->tail)->next = createNode(data);
        ((list->tail)->next)->pre = list->tail;
        list->tail = (list->tail)->next;
    }
}

void pushAtPosition(list *list, int data, int position)
{
    if (list->head == NULL)
    {
        printf("list not existing.");
        return;
    }
    if (position <= 0)
    {
        printf("position should be only natural number.\n");
        return;
    }
    if (position == 1)
    {
        pushFrunt(list, data);
        return;
    }
    node *ptr = list->head;
    for (int i = 0; i < position - 2; i++)
    {
        if (ptr->next == NULL)
        {
            printf("the position is not valid.\n");
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        pushBack(list, data);
        return;
    }
    ptr->next->pre = createNode(data);
    ptr->next->pre->next = ptr->next;
    ptr->next->pre->pre = ptr;
    ptr->next = ptr->next->pre;
}

void deleteFromFrunt(list *list)
{
    if (list->head == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        free(list->head->pre);
    }
}

void deletfromEnd(list *list)
{
    if (list->head == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->pre;
        free(list->tail->next);
        list->tail->next = NULL;
    }
}

void deleteFromPosition(list *list, int position)
{
    if (position <= 0)
    {
        printf("position should be natural number only.\n");
        return;
    }
    if (list->head == NULL)
    {
        printf("list not existing.\n");
        return;
    }
    if (position == 1)
    {
        deleteFromFrunt(list);
        return;
    }
    node *ptr = list->head;
    for (int i = 0; i < position - 2; i++)
    {
        if (ptr->next == NULL)
        {
            printf("invalid position.\n");
            return;
        }
        ptr = ptr->next;
    }
    // edge case is there is only 1 node and position is 2
    if (ptr->next == NULL)
    {
        printf("invalid position.\n");
        return;
    }
    if (ptr->next->next == NULL)
    {
        deletfromEnd(list);
        return;
    }
    node *selectedNode = ptr->next;
    ptr->next = selectedNode->next;
    ptr->next->pre = ptr;
    free(selectedNode);
}

void displayList(list *list)
{
    node *ptr = list->head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" <=> ");
        }
    }
    printf("\n");
    // printf("%d", list->tail);
}
int main()
{
    list dll;
    dll.head = NULL;
    dll.tail = NULL;

    pushFrunt(&dll, 50);
    pushFrunt(&dll, 40);
    pushFrunt(&dll, 30);
    pushFrunt(&dll, 20);
    pushFrunt(&dll, 10);

    displayList(&dll);
    
    pushBack(&dll, 60);
    pushBack(&dll, 70);
    pushBack(&dll, 80);

    displayList(&dll);

    deleteFromFrunt(&dll);

    displayList(&dll);

    deletfromEnd(&dll);
    deletfromEnd(&dll);
    deletfromEnd(&dll);

    displayList(&dll);

    pushAtPosition(&dll, 33, 5);
    pushAtPosition(&dll, 44, 3);
    pushAtPosition(&dll, 55, 5);
    pushAtPosition(&dll, 66, 6);

    displayList(&dll);

    deleteFromPosition(&dll, 3);
    deleteFromPosition(&dll, 7);

    displayList(&dll);
    return 0;
}