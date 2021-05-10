#include "BubbleSort.hh"
#include "Ultility.hh"

BubbleSort::BubbleSort(int arr[], int size) {
    BubbleSorting(arr, size);
}

void BubbleSort::BubbleSorting(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool sorted = true;
        for (int j = 0; j < size-i-1; j++)
            if (arr[j] > arr[j + 1]) {
                Ultility::Swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        if (sorted) break;
    }
}

