#include "CocktailSort.hh"
#include "Ultility.hh"

CocktailSort::CocktailSort(int arr[], int size) {
    CocktailSorting(arr, size);
}

void CocktailSort::CocktailSorting(int arr[], int size) {
    bool sorted = false;
    int start = 0;
    int end = size - 1;

    while (!sorted) {
        sorted = true;

        // Forth
        for (int i = start; i < end; i++)
            if (arr[i] > arr[i + 1]) {
                Ultility::Swap(arr[i + 1], arr[i]);
                sorted = false;
            }

        if (sorted) break;
        sorted = true;
        end--;

        // Back
        for (int i = end - 1; i > start - 1; i--)
            if (arr[i] > arr[i + 1]) {
                Ultility::Swap(arr[i + 1], arr[i]);
                sorted = false;
            }

        start++;
    }
}