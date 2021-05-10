#include "CycleSort.hh"
#include "Ultility.hh"

CycleSort::CycleSort(int arr[], int size) {
    CycleSorting(arr, size);
}

void CycleSort::CycleSorting(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int checkVal = arr[i];
        int checkIdx = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] < checkVal)
                checkIdx++;
        
        if (checkIdx == i) continue;

        while (arr[checkIdx] == checkVal)
            checkIdx++;

        Ultility::Swap(arr[checkIdx], checkVal);

        while (checkIdx != i) {
            checkIdx = i;

            for (int j = i + 1; j < size; j++)
                if (arr[j] < checkVal)
                    checkIdx++;

            while (arr[checkIdx] == checkVal)
                checkIdx++;

            Ultility::Swap(arr[checkIdx], checkVal);
        }
    }
}
