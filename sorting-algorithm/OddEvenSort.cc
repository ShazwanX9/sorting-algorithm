#include "OddEvenSort.hh"
#include "Ultility.hh"

OddEvenSort::OddEvenSort(int arr[], int size) {
    OddEvenSorting(arr, size);
}

void OddEvenSort::OddEvenSorting(int arr[], int size) {
    int sorted = false;

    while (!sorted) {
        sorted = true;
        // odd
        for (int i = 1; i < size -1; i+=2) 
            if (arr[i] > arr[i+1]) {
                Ultility::Swap(arr[i], arr[i+1]);
                sorted = false;
            }

        // even
        for (int i = 0; i < size - 1; i+=2) 
            if (arr[i] > arr[i+1]) {
                Ultility::Swap(arr[i], arr[i+1]);
                sorted = false;
            }
    }
}
