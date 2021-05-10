// https://en.wikipedia.org/wiki/Insertion_sort

#ifndef _BINARY_INSERTION_SORT
#define _BINARY_INSERTION_SORT

class BinarySort {
    protected:
        BinarySort();
        int IterativeBinarySearch(int[], int, int, int);
        int RecursiveBinarySearch(int[], int, int, int);
        void BinaryInsertionSort(int[], int);
    public:
        BinarySort(int[], int);
};

#endif