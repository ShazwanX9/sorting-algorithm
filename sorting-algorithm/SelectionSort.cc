#include "SelectionSort.hh"
#include "Ultility.hh"

SelectionSort::SelectionSort(int arr[], int size) {
    SelectionSorting(arr, size);
}

void SelectionSort::SelectionSorting(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i; j < size; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        Ultility::Swap(arr[minIdx], arr[i]);
    }
}
