# Building Min Heap and Max Heap from an Unsorted Array

## Data Structure

Heaps are complete binary trees represented as arrays:  
- **Max Heap:** parent ≥ children  
- **Min Heap:** parent ≤ children  
- Indexing rules for node at `i`:  
  - Left child → `2*i + 1`  
  - Right child → `2*i + 2`  

## Functions

swap(a, b) → Swaps two integers  

heapifyMax(arr, n, i) → Adjusts subtree rooted at `i` to maintain **Max Heap** property  

heapifyMin(arr, n, i) → Adjusts subtree rooted at `i` to maintain **Min Heap** property  

buildMaxHeap(arr, n) → Builds a max heap from an unsorted array  

buildMinHeap(arr, n) → Builds a min heap from an unsorted array  

display(arr, n) → Prints the array elements

## Main Function

- Reads number of elements and array from the user  
- Copies the array into two separate arrays for max and min heaps  
- Builds max heap and min heap using respective functions  
- Displays both heaps

## Sample Output

Enter number of elements: 6  
Enter the elements: 5 3 8 4 1 7  

Max Heap: 8 5 7 4 1 3  
Min Heap: 1 3 5 4 8 7

## Conclusion

This program demonstrates building **Max Heap** and **Min Heap** from an unsorted array using heapify operations.  
It shows how binary heap properties can be maintained efficiently in array representation.