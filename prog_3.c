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

    printf("\nLinked List (Forward): ");
    displayForward(head);

    printf("\nLinked List (Reverse Traversal): ");
    displayReverse(head);

    return 0;
}