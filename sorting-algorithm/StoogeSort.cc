#include "StoogeSort.hh"
#include "Ultility.hh"

StoogeSort::StoogeSort(int arr[], int size) {
    StoogeSorting(arr, size, 0, size);
}

StoogeSort::StoogeSort(int arr[], int size, int low, int high) {
    StoogeSorting(arr, size, low, high);
}

void StoogeSort::StoogeSorting(int arr[], int size, int low, int high) {
    if (low >= high) return;

    if (arr[low] > arr[high]) {
        int mid = (high + low) / 2;
        Ultility::Swap(arr[low], arr[high]);
    }

    if ((high - low + 1) > 2) {
        int temp = (high - low + 1) / 3;
        StoogeSort(arr, size, low, high - temp);
        StoogeSort(arr, size, low + temp, high);
        StoogeSort(arr, size, low, high - temp);
    }
}