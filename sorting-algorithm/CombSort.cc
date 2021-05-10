#include "CombSort.hh"
#include "Ultility.hh"

CombSort::CombSort(int arr[], int size) {
    CombSorting(arr, size);
}

int CombSort::get_gap(int prevGap) {
    int gap = prevGap/1.3;
    return (gap < 1) ? 1 : gap;
}

void CombSort::CombSorting(int arr[], int size) {
    int gap = size;
    bool sorted = false;

    while (gap != 1 || !sorted) {
        gap = get_gap(gap);
        sorted = true;

        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                Ultility::Swap(arr[i], arr[i + gap]);
                sorted = false;
            }
        }
    }
}