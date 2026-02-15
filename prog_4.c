#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* prevNode, int value)
{
    if (prevNode == NULL)
        return;

    struct Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

void deleteNode(struct Node** head, struct Node* target)
{
    if (*head == NULL || target == NULL)
        return;

    if (*head == target)
        *head = target->next;

    if (target->next != NULL)
        target->next->prev = target->prev;

    if (target->prev != NULL)
        target->prev->next = target->next;

    free(target);
}

void displayForward(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayBackward(struct Node* tail)
{
    struct Node* temp = tail;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original List Forward: ");
    displayForward(head);

    insertAfter(second, 25);
    printf("\nAfter Inserting 25 after 20: ");
    displayForward(head);

    deleteNode(&head, second);
    printf("\nAfter Deleting 20: ");
    displayForward(head);

    printf("\nList Backward from last node: ");
    displayBackward(third);

    return 0;
}