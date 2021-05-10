#include "PancakeSort.hh"
#include "Ultility.hh"

PancakeSort::PancakeSort(int arr[], int size) {
    PancakeSorting(arr, size);
}

int PancakeSort::get_max_idx(int arr[], int size) {
    int idx = 0;
    for(int i = 0; i < size; i++)
        if(arr[i] > arr[idx])
            idx = i;
    return idx;
}

void PancakeSort::flip (int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if (i >= size - i) break;
        Ultility::Swap(arr[size - i], arr[i]);
    }
}

void PancakeSort::PancakeSorting(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int maxIdx = get_max_idx(arr, size - i);
        flip(arr, maxIdx);
        flip(arr, size - 1 - i);
    }
}

