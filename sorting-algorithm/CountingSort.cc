#include "CountingSort.hh"
#include "Ultility.hh"

CountingSort::CountingSort(int arr[], int size) {
    CountingSorting(arr, size);
}

void CountingSort::CountingSorting(int arr[], int size)  {   
    int max = Ultility::GetMax(arr, size);
    int count[max + 1], result[size];

    // initialize with 0's
    for (int i = 0; i <= size; i++)
        arr[i] = 0;

    // Counting each number
    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    // Carry forward previous count
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Placing number count on its index 
    // [-1 cause index start with 0]
    for (int i = size - 1; i >= 0; i--) {
        result[ count[ arr[i] ] -1 ] = arr[i];
        count[arr[i]]--;
    }

    // copy the result to returning array
    for (int i = 0; i < size; i++)
        arr[i] = result[i];
}