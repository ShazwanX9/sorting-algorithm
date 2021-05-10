#include "MergeSort.hh"
#include "Ultility.hh"

MergeSort::MergeSort(int arr[], int size) {
    MergeSorting(arr, size, 0, size);
}

MergeSort::MergeSort(int arr[], int size, int low, int high) {
    MergeSorting(arr, size, low, high);
}

void MergeSort::MergeSorting(int arr[], int size, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arr, size, low, mid);
        MergeSort(arr, size, mid + 1, high);
        Ultility::Merge(arr, low, mid, high);
    }
}