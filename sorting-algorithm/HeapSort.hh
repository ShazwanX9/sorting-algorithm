// https://en.wikipedia.org/wiki/Heapsort

#ifndef _HEAP_SORT
#define _HEAP_SORT

class HeapSort {
    void HeapSorting(int[], int);
    void shiftDown(int[], int, int);
    void heapify(int[], int);
    public:
        HeapSort(int[], int);
};

#endif