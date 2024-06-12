#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function
int partition(int arr[], int low, int high)
{
    // initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {

        // condition 1: find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // condition 2: find the first element smaller than
        // the pivot (from last)
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // call Partition function to find Partition Index
        int partitionIndex = partition(arr, low, high);
        // Recursively call quickSort() for left and right
        // half based on partition Index
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
// driver code
int main()
{
    int i, n;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the value of n:");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    start = clock();
    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printing the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}