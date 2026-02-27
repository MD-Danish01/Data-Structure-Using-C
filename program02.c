/*
Write a C program to implement a singly linked list using structures, with functionalities 
for insertion, deletion (at beginning, end, and specific position), and traversal. 
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct node **list, int data)
{
    if (*list == NULL)
    {
        *list = createNode(data);
    }
    else
    {
        struct node *temp;
        temp = createNode(data);
        temp->next = *list;
        *list = temp;
    }
}

void insertAtEnd(struct node **list, int data)
{
    if (*list == NULL)
    {
        *list = createNode(data);
    }
    else
    {
        struct node *tail = *list;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = createNode(data);
    }
}

void insertAtSpecificPosition(struct node **list, int data, int position)
{
    if (*list == NULL)
    {
        printf("the list is not existing.");
        return;
    }

    if (position <= 0)
    {
        printf("positions are allways natural number\n");
    }
    else
    {
        struct node *ptr = *list;
        // check if position is 1
        if (position == 1)
        {
            *list = createNode(data);
            (*list)->next = ptr;
            return;
        }
        for (int i = 1; i < position - 1; i++)
        {
            if (ptr->next == NULL)
            {
                printf("position is greator than number of nodes in list.\n");
                return;
            }
            ptr = ptr->next;
        }

        struct node *remainingList = ptr->next;
        ptr->next = createNode(data);
        ptr = ptr->next;
        ptr->next = remainingList;
    }
}

void deleteFromBeginning(struct node **list)
{
    struct node *temp = *list;
    if (temp == NULL)
    {
        printf("list is empty.\n");
        return;
    }
    *list = temp->next;
    free(temp);
}

void deleteFromEnd(struct node **list)
{
    struct node *ptr = *list;
    if (ptr == NULL)
    {
        printf("list is empty.\n");
        return;
    }
    // check is there only one node
    if (ptr->next == NULL)
    {
        free(ptr);
        *list = NULL;
        return;
    }
    while (1)
    {
        if ((ptr->next)->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void deleteFromSpecificPosition(struct node **list, int position)
{
    struct node *ptr = *list;
    if (ptr == NULL)
    {
        printf("list is empty.\n");
        return;
    }
    if (position <= 0)
    {
        printf("position should be natural number.\n");
        return;
    }

    // check if position is 1
    if (position == 1)
    {
        *list = ptr->next;
        free(ptr);
        return;
    }

    for (int i = 1; i < position - 1; i++)
    {
        if (ptr->next == NULL)
        {
            printf("position is greater than number of nodes in list.\n");
            return;
        }
        ptr = ptr->next;
    }
    //edge case: when there is 1 node and position is 2
    if (ptr->next == NULL)
    {
        printf("position is greater than number of nodes in list.\n");
        return;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void displayList(struct node **list)
{
    if (*list == NULL)
    {
        printf("the list is not existing.");
        return;
    }
    struct node *ptr = *list;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL)
            printf(" -> ");
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 0);
    insertAtEnd(&head, 60);
    insertAtEnd(&head, 70);
    insertAtEnd(&head, 80);
    insertAtEnd(&head, 90);

    displayList(&head);

    insertAtSpecificPosition(&head, 3, 3);
    insertAtSpecificPosition(&head, 4, 4);
    insertAtSpecificPosition(&head, 10, 10);
    insertAtSpecificPosition(&head, 121, 11);

    displayList(&head);

    deleteFromBeginning(&head);

    displayList(&head);

    deleteFromEnd(&head);

    displayList(&head);

    deleteFromSpecificPosition(&head, 9);

    displayList(&head);

    return 0;
}
