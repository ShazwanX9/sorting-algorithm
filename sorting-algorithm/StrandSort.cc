#include "StrandSort.hh"
#include "Ultility.hh"
#include <vector>

StrandSort::StrandSort(int arr[], int size) {
    StrandSorting(arr, size);
}

void StrandSort::StrandSorting(int arr[], int size, int start) {

    if (start == size) return;

    std::vector <int> result(arr + 0, arr + size);

    int i = start + 1;
    int count = start + 1;

    while (i < size) {
        if (arr[i] > arr[count-1]) {\
            int temp = arr[i];
            result.erase(result.begin() + i);
            result.insert(result.begin() + count, temp);
            count++;
        }
        i++;
    }
    if (start != 0) {
        for(int i = 0; i < size; i++)
            arr[i] = result[i];
        Ultility::Merge(arr, 0, start - 1, count - 1);
    }

    StrandSorting(arr, size, count);
}