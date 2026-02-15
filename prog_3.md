# Program: Reverse Traversal of a Linked List Using Recursion

## Explanation of Data Structure

This program uses a Singly Linked List.  
Each node contains:
- An integer data value  
- A pointer to the next node  

struct Node  
{  
    int data;  
    struct Node* next;  
};  

The list starts from a pointer called head. If head is NULL, the list is empty.  
Reverse traversal is done using recursion without modifying the original list.

## Description of Functions

createNode(int value)  
Creates a new node dynamically and initializes its data and next pointer.

insertAtEnd(struct Node** head, int value)  
Inserts a new node at the end of the list. If the list is empty, the new node becomes the head.

displayForward(struct Node* head)  
Traverses and prints elements from beginning to end.

displayReverse(struct Node* head)  
Uses recursion to print elements in reverse order by first reaching the last node and printing while returning.

## Overview of main() Function

The main function:
- Initializes the list
- Takes user input
- Inserts elements into the linked list
- Displays the list in forward order
- Displays the list in reverse order

## Complete Program

```
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
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

void displayReverse(struct Node* head)
{
    if (head == NULL)
        return;

    displayReverse(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("\nForward: ");
    displayForward(head);

    printf("\nReverse: ");
    displayReverse(head);

    return 0;
}
```

## Sample Output

```
Enter number of elements: 3
Enter value: 10
Enter value: 20
Enter value: 30

Forward: 10 20 30
Reverse: 30 20 10
```

## Conclusion

This program demonstrates reverse traversal of a singly linked list using recursion. The list structure remains unchanged while elements are displayed in reverse order.