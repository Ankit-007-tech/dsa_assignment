# Doubly Linked List with Insertion and Deletion

## Data Structure

A doubly linked list has nodes containing:
- `data` → integer value  
- `prev` → pointer to previous node  
- `next` → pointer to next node  

struct Node  
{  
    int data;  
    struct Node* prev;  
    struct Node* next;  
};  

Head points to the first node. The list allows traversal forward and backward.

## Functions

createNode(value) → Creates a new node with given data.  
insertAfter(prevNode, value) → Inserts a node after a specified node.  
deleteNode(head, target) → Deletes the given node and updates neighbors.  
displayForward(head) → Prints the list from head to tail.  
displayBackward(tail) → Prints the list from tail to head.

## Main Function

- Creates three initial nodes (10, 20, 30)  
- Displays the list forward  
- Inserts 25 after node with 20  
- Deletes node with 20  
- Displays list forward and backward

## Program

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
    if (prevNode == NULL) return;
    struct Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

void deleteNode(struct Node** head, struct Node* target)
{
    if (*head == NULL || target == NULL) return;
    if (*head == target) *head = target->next;
    if (target->next != NULL) target->next->prev = target->prev;
    if (target->prev != NULL) target->prev->next = target->next;
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
    head->next = second; second->prev = head;
    second->next = third; third->prev = second;

    printf("Original Forward: "); displayForward(head);
    insertAfter(second, 25);
    printf("\nAfter Inserting 25: "); displayForward(head);
    deleteNode(&head, second);
    printf("\nAfter Deleting 20: "); displayForward(head);
    printf("\nBackward from last: "); displayBackward(third);

    return 0;
}

## Sample Output

Original Forward: 10 20 30  
After Inserting 25: 10 20 25 30  
After Deleting 20: 10 25 30  
Backward from last: 30 25 10

## Conclusion

This program demonstrates how to implement a doubly linked list in C,  
showing insertion after a given node, deletion of a node,  
and traversal in both forward and backward directions.