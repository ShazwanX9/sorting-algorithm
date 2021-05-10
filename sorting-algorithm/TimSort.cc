#include "TimSort.hh"
#include "Ultility.hh"

TimSort::TimSort(int arr[], int size) {
    TimSorting(arr, size, 0, size);
}

int TimSort::calculate_min_run(int size) {
    int lastBit = 0;
    int runLen  = 32;

    while (size >= runLen) {
        lastBit |= size & 1;
        size >>= 1;
    }

    return size + lastBit;
}

void TimSort::BinaryInsertionSort(int arr[], int start, int stop) {
    for (int i = start; i < stop + 1; i++) {
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

void TimSort::TimSorting(int arr[], int size, int start, int end) {
    int minRun = calculate_min_run(size);

    for (int i = 0; i < size; i += minRun) {
        int stop = Ultility::CompMin(start + minRun - 1, size - 1);
        BinaryInsertionSort(arr, start, stop);
    }

    int gap = minRun;
    while (gap < size) {
        for (int left = 0; left < size; left += 2 * gap) {
            int mid     = Ultility::CompMin(size - 1, left + gap - 1);
            int right   = Ultility::CompMin(left + 2 * gap - 1, size - 1);
            Ultility::Merge(arr, left, mid, right);
        }
        gap *= 2;
    }
}