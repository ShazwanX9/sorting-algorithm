#include "QuickSort.hh"
#include "Ultility.hh"
#include <cstdlib>
#include <ctime>

QuickSort::QuickSort(int arr[], int size) {
    // Uncomment for Lomuto
    // srand(time(0)); 
    QuickSorting(arr, size, 0, size);
}

QuickSort::QuickSort(int arr[], int size, int low, int high) {
    // Uncomment for Lomuto
    // srand(time(0));
    QuickSorting(arr, size, low, high);
}

void QuickSort::QuickSorting(int arr[], int size, int low, int high) {
    if (low >= high)
        return;

    // int partition = LomutoPartition(arr, size, low, high);
    int partition = HoarePartition(arr, size, low, high);

    QuickSorting(arr, size, low, partition); // (partition - 1) if Lomuto
    QuickSorting(arr, size, partition + 1, high);
}

int QuickSort::LomutoPartition(int arr[], int size, int low, int high) {
    int idx = low;
    int randIdx = low + rand() % (high - low + 1);

    Ultility::Swap(arr[randIdx], arr[high]);

    for (int j = low; j < high; j++)
        if (arr[j] < arr[high]) {
            Ultility::Swap(arr[j], arr[idx]);
            idx++;
        }

    Ultility::Swap(arr[high], arr[idx]);

    return idx;
}

int QuickSort::HoarePartition(int arr[], int size, int low, int high) {
    int i     = low - 1;
    int j     = high + 1;
    int pivot = arr[low];

    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        Ultility::Swap(arr[i], arr[j]);
    }
}
