/*
Write a C program to implement a singly linked list using structures, with functionalities 
for insertion, deletion (at beginning, end, and specific position), and traversal. 
*/

#include <stdio.h>
#include <stdlib.h>

/* ── Node structure ─────────────────────────────────────────────────────── */
struct Node {
    int data;
    struct Node *next;
};

/* ── Utility: create a new node ─────────────────────────────────────────── */
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* ── Traversal ──────────────────────────────────────────────────────────── */
void traverse(struct Node *head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

/* ── Insertion at the beginning ─────────────────────────────────────────── */
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    printf("Inserted %d at beginning.\n", data);
    return newNode;
}

/* ── Insertion at the end ───────────────────────────────────────────────── */
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (!head) {
        printf("Inserted %d at end (list was empty).\n", data);
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    printf("Inserted %d at end.\n", data);
    return head;
}

/* ── Insertion at a specific position (1-based) ─────────────────────────── */
struct Node *insertAtPosition(struct Node *head, int data, int pos) {
    if (pos <= 1)
        return insertAtBeginning(head, data);

    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;

    if (!temp) {
        printf("Position %d out of range. Inserting at end instead.\n", pos);
        /* reuse insertAtEnd logic */
        struct Node *t = head;
        if (!t) return newNode;
        while (t->next) t = t->next;
        t->next = newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
    return head;
}

/* ── Deletion at the beginning ──────────────────────────────────────────── */
struct Node *deleteAtBeginning(struct Node *head) {
    if (!head) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

/* ── Deletion at the end ────────────────────────────────────────────────── */
struct Node *deleteAtEnd(struct Node *head) {
    if (!head) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    if (!head->next) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next)
        temp = temp->next;
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

/* ── Deletion at a specific position (1-based) ──────────────────────────── */
struct Node *deleteAtPosition(struct Node *head, int pos) {
    if (!head) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    if (pos <= 1)
        return deleteAtBeginning(head);

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next; i++)
        temp = temp->next;

    if (!temp->next) {
        printf("Position %d out of range. No deletion performed.\n", pos);
        return head;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, pos);
    free(toDelete);
    return head;
}

/* ── Free the entire list ───────────────────────────────────────────────── */
void freeList(struct Node *head) {
    struct Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ── Main ───────────────────────────────────────────────────────────────── */
int main(void) {
    struct Node *head = NULL;

    printf("=== Singly Linked List Operations ===\n\n");

    /* --- Insertions --- */
    printf("-- Insertion --\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    traverse(head);

    head = insertAtBeginning(head, 5);
    traverse(head);

    head = insertAtPosition(head, 25, 4);   /* insert 25 at position 4 */
    traverse(head);

    /* --- Deletions --- */
    printf("\n-- Deletion at Beginning --\n");
    head = deleteAtBeginning(head);
    traverse(head);

    printf("\n-- Deletion at End --\n");
    head = deleteAtEnd(head);
    traverse(head);

    printf("\n-- Deletion at Position 3 --\n");
    head = deleteAtPosition(head, 3);
    traverse(head);

    printf("\n-- Deletion at Out-of-Range Position (10) --\n");
    head = deleteAtPosition(head, 10);
    traverse(head);

    freeList(head);
    return 0;
}
