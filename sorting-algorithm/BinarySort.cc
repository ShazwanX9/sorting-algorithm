#include "BinarySort.hh"

BinarySort::BinarySort() {}

BinarySort::BinarySort(int arr[], int ele) {
    BinaryInsertionSort(arr, ele);
}

int BinarySort::IterativeBinarySearch(int arr[], int ele, int start, int end) {

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele) return mid;
        (arr[mid] < ele) ? start = mid + 1 : end = mid - 1;
    }

    return (arr[start] < ele)? start + 1 : start;
}

int BinarySort::RecursiveBinarySearch(int arr[], int ele, int start, int end) {
    if (start >= end)
        return (arr[start] < ele)? start + 1 : start;

    int mid = start + (end - start) / 2;
    if (arr[mid] == ele) return mid;
    return (arr[mid] < ele) ? 
        RecursiveBinarySearch(arr, ele, mid + 1, end): 
        RecursiveBinarySearch(arr, ele, start, mid - 1);
}

void BinarySort::BinaryInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int checkVal = arr[i];
        int checkIdx = i - 1;

        int res = RecursiveBinarySearch(arr, checkVal, 0, checkIdx);

        while (checkIdx >= res) {
            arr[checkIdx+1] = arr[checkIdx];
            checkIdx--;
        }
        arr[checkIdx+1] = checkVal;
    }
}