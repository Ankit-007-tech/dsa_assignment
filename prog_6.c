#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxHeap[n], minHeap[n];
    for(int i = 0; i < n; i++)
    {
        maxHeap[i] = arr[i];
        minHeap[i] = arr[i];
    }

    buildMaxHeap(maxHeap, n);
    buildMinHeap(minHeap, n);

    printf("\nMax Heap: ");
    display(maxHeap, n);

    printf("Min Heap: ");
    display(minHeap, n);

    return 0;
}