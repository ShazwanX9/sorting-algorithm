#include "BogoSort.hh"
#include "Ultility.hh"
#include <cstdlib>
#include <ctime>

BogoSort::BogoSort(int arr[], int size) {
    srand(time(0));
    BogoSorting(arr, size);
}

void BogoSort::BogoSorting(int arr[], int size) {
    bool sorted = false;
    while (!sorted) {
        // SHUFFLE
        for (int i = 0; i < size; i ++) {
            int swapWith = rand()%size;
            Ultility::Swap(arr[swapWith], arr[i]);
        }

        // CHECK SORTED
        for (int i = 0; i < size; i ++) {
            if (arr[i] > arr[i+1]) {
                sorted = false;
                break;
            }
            sorted = true;
        }
    }
}