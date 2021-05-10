#include "InsertionSort.hh"

InsertionSort::InsertionSort(int arr[], int size) {
    InsertionSorting(arr, size);
}

void InsertionSort::InsertionSorting(int arr[], int size)  {
    for (int i = 0; i < size; i++) {
        int checkIdx = i - 1;
        int checkVal = arr[i];
        while (checkIdx >= 0 && arr[checkIdx] > checkVal) {
            arr[checkIdx + 1] = arr[checkIdx];
            checkIdx--;
        }
        arr[checkIdx + 1] = checkVal;
    }
}