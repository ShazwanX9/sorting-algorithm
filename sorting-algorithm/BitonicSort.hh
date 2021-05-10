// https://en.wikipedia.org/wiki/Bitonic_sorter

#ifndef _BITONIC_SORT
#define _BITONIC_SORT

class BitonicSort {
     int GreatestPowerOfTwoLessThan(int);
    void Bitonic(int[], int, int, bool);
    void CompNSwap(int[], int, int, bool);
    void BitonicMerge(int[], int, int, bool);
    public:
        BitonicSort(int[], int);
};

#endif