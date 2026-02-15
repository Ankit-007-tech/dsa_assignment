#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void bubbleSort(int arr[], int n)
{
    comparisons = 0; swaps = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            comparisons++;
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n)
{
    comparisons = 0; swaps = 0;
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            comparisons++;
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[], int n)
{
    comparisons = 0; swaps = 0;
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j+1] = arr[j];
            swaps++;
            j--;
        }
        if(j >= 0) comparisons++;
        arr[j+1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        comparisons++;
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
        {
            arr[k++] = R[j++];
            swaps++;
        }
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, choice;
    printf("Enter the number of random elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("Generated numbers:\n");
    display(arr, n);

    printf("\nChoose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: comparisons = 0; swaps = 0; mergeSort(arr, 0, n-1); break;
        default: printf("Invalid choice\n"); return 0;
    }

    printf("\nSorted numbers:\n");
    display(arr, n);
    printf("Total comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);

    return 0;
}