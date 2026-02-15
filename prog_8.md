# Sorting Random Numbers with User-Selected Algorithm

## Data Structure

- Array of integers stores randomly generated numbers  
- `comparisons` and `swaps` track operations performed by the chosen sorting algorithm  

## Functions

swap(a, b) → Swaps two array elements and counts a swap  

bubbleSort(arr, n) → Sorts using **Bubble Sort**, counting comparisons and swaps  

selectionSort(arr, n) → Sorts using **Selection Sort**, counting comparisons and swaps  

insertionSort(arr, n) → Sorts using **Insertion Sort**, counting comparisons and swaps  

mergeSort(arr, l, r) → Sorts using **Merge Sort** recursively, counting comparisons and swaps  

merge(arr, l, m, r) → Helper for mergeSort to combine two sorted halves  

display(arr, n) → Prints the array elements

## Main Function

- Takes number of elements as input  
- Generates an array of random numbers in range [1, 1000]  
- Displays the unsorted numbers  
- Lets user choose a sorting algorithm (Bubble, Selection, Insertion, Merge)  
- Sorts the array using the chosen algorithm  
- Displays sorted numbers along with **total comparisons and swaps**

## Sample Input/Output

Enter the number of random elements: 6  
Generated numbers: 523 101 876 432 654 215  

Choose sorting algorithm:  
1. Bubble Sort  
2. Selection Sort  
3. Insertion Sort  
4. Merge Sort  
Enter your choice: 1  

Sorted numbers: 80 59 646 645 602 624 
Total comparisons: 15  
Total swaps: 6

## Conclusion

This program demonstrates how to generate a **random array**, sort it using a **user-selected algorithm**,  
and track the **number of comparisons and swaps** performed.  
It allows analysis of algorithm efficiency on randomly generated data.