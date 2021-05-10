#include <vector>
#include <algorithm>
#include "BucketSort.hh"

BucketSort::BucketSort(int arr[], int size) {
    BucketSorting(arr, size);
}

void BucketSort::BucketSorting(int arr[], int size) {
    // assume every bucket as MAX
    std::vector<int>bucket[size];

    // Scatter : fill every bucket with element divisible by size 
    for (int i = 0; i < size; i++) {
        int tempIdx = arr[i] / size; 
        bucket[tempIdx].push_back(arr[i]);
    }

    // sort Individual element
    for(int i = 0; i<size; i++)
        sort(bucket[i].begin(), bucket[i].end());

    // Gather : merge every element in sorted bucket
    for (int i = 0, tempIdx = 0; i < size; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[tempIdx] = bucket[i][j];
            tempIdx++;
        }
    }
}

