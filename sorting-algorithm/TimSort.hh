// https://en.wikipedia.org/wiki/Timsort

#include "BinarySort.hh"

#ifndef _TIM_SORT
#define _TIM_SORT

class TimSort : public BinarySort {
    void TimSorting(int[], int, int, int);
    void BinaryInsertionSort(int[], int, int);
     int calculate_min_run(int);
    public:
        TimSort(int[], int);
};

#endif