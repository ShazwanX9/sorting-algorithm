#include "BitonicSort.hh"

BitonicSort::BitonicSort(int arr[], int size) {
    Bitonic(arr, 0, size, true);
}

int BitonicSort::GreatestPowerOfTwoLessThan(int n) {
    int k = 1;
    while (k && k < n)
        k <<= 1;
    return k >> 1;
}

void BitonicSort::CompNSwap(int arr[], int first, int second, bool dir) {
    if ((dir && arr[first] > arr[second]) || (!dir && arr[first] <= arr[second])) {
        int temp    = arr[first];
        arr[first]  = arr[second];
        arr[second] = temp;
    }
}

void BitonicSort::BitonicMerge(int arr[], int start, int end, bool dir) {
    if (end > 1) {
        int k = GreatestPowerOfTwoLessThan(end);
        for (int i = 0; i < start + end - k; i++)
            CompNSwap(arr, i, i + k, dir);
        BitonicMerge(arr, start, k, dir);
        BitonicMerge(arr, start + k, end - k, dir);
    }
}

void BitonicSort::Bitonic(int arr[], int start, int end, bool dir) {
    if (end > 1) {
        int k = end / 2;
        Bitonic(arr, start, k, !dir);
        Bitonic(arr, start+k, end - k, dir);
        BitonicMerge(arr, start, end, dir);
    }
}
