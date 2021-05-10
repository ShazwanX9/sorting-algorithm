#include "HeapSort.hh"
#include "Ultility.hh"

HeapSort::HeapSort(int arr[], int size) {
    HeapSorting(arr, size);
}

void HeapSort::shiftDown(int arr[], int start, int end) {
    int root = start;
    while (2 * root + 1 <= end) {

        int child = 2 * root + 1;
        int swap = root;

        if (arr[swap] < arr[child])
            swap = child;
        if (child + 1 <= end && arr[swap] < arr[child + 1])
            swap = child + 1;

        if (swap == root) return;
        else {
            Ultility::Swap(arr[root], arr[swap]);
            root = swap;
        }

    }
}

void HeapSort::heapify(int arr[], int count) {
    int start = (count - 1) / 2;
    while (start >= 0) {
        shiftDown(arr, start, count - 1);
        start--;
    }    
}

void HeapSort::HeapSorting(int arr[], int size) {
    heapify(arr, size);
    int end = size -1;
    while (end > 0) {
        Ultility::Swap(arr[end], arr[0]);
        end--;
        shiftDown(arr, 0, end);
    }
}
