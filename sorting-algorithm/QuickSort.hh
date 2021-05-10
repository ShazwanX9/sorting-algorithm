// https://en.wikipedia.org/wiki/Quicksort

#ifndef _QUICK_SORT
#define _QUICK_SORT

/*
    Hoare’s scheme is more efficient
    than Lomuto’s partition scheme because
    it does three times fewer swaps on average,
    and it creates efficient partitions
    even when all values are equal.
    
    Like Lomuto’s partition scheme,
    Hoare partitioning also causes Quick sort
    to degrade to O(n^2) when
    the input array is already sorted,
    it also doesn’t produce a stable sort.
    
    Note that in this scheme,
    the pivot’s final location
    is not necessarily at the indexthat was returned,
    and the next two segments that the main algorithm
    recurs on are (lo..p) and (p+1..hi)
    as opposed to (lo..p-1) and (p+1..hi)
    as in Lomuto’s scheme.
*/

class QuickSort {
    void QuickSorting(int[], int, int, int);
     int LomutoPartition(int[], int, int, int);
     int HoarePartition(int[], int, int, int);
    public:
        QuickSort(int[], int);
        QuickSort(int[], int, int, int);
};

#endif