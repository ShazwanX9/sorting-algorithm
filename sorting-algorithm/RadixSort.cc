#include "RadixSort.hh"
#include "Ultility.hh"

RadixSort::RadixSort(int arr[], int size) {
    RadixSorting(arr, size);
}

int radixCounting(int arr[], int size, int expo) {
    int results[size];

    for(int i = 0; i < size; i++)
        results[i] = arr[i];

    int count[10];
    for(int i = 0; i < 10; i++)
        count[i] = 0;

    for(int i = 0; i < size; i++) {
        int idx = arr[i] / expo;
        count[idx % 10] += 1;
    }

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    int i = size - 1;
    while (i >= 0) {
        int idx = arr[i] / expo;
        results[count[idx % 10] - 1] = arr[i];
        count[idx % 10]--;
        i--;
    }
    i = 0;

    if (arr == results) return 0; // all done

    for (int i = 0; i < size; i++)
        arr[i] = results[i];
    
    return -1; // not done yet
}

void RadixSort::RadixSorting(int arr[], int size) {
    int maxVal = Ultility::GetMax(arr, size);
    int g = 1;
    int expo = 1;
    while (maxVal / expo > 0) {
        g = radixCounting(arr, size, expo);
        if (!g) break;
        expo *= 10;
    }
}