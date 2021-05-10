#include "GnomeSort.hh"
#include "Ultility.hh"

GnomeSort::GnomeSort(int arr[], int size) {
    GnomeSorting(arr, size);
}

void GnomeSort::GnomeSorting(int arr[], int size) {
    for (int i = 0; i < size; )
        if (i && arr[i - 1] > arr[i]) {
            Ultility::Swap(arr[i - 1], arr[i]);
            i--;
        } else i++;
}