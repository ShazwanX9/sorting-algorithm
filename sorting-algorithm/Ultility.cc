#include "Ultility.hh"

void Ultility::Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Ultility::Merge(int arr[], int low, int mid, int high) {
    // sub-array
    int nl = mid - low + 1, nr = high - mid;
    int larr[nl], rarr[nr];

    for (int i = 0; i < nl; i++)
        larr[i] = arr[low + i];

    for (int i = 0; i < nr; i++)
        rarr[i] = arr[ mid + 1 + i];

    // merge temp to real
    int i = 0, j = 0, k = low;
    while ( i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        }
        else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    // low extras
    while (i < nl) {
        arr[k] = larr[i];
        i++; k++;
    }

    // high extras
    while (j < nr) {
        arr[k] = rarr[j];
        j++; k++;
    }
    
}

int Ultility::GetMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int Ultility::CompMin(int a, int b) {
    return (a < b) ? a : b;
}

int Ultility::Pow(int base, int expo) {
    int x = 1;
    for (int i = 0; i < expo; i++)
        x *= base;
    return x;
}

int Ultility::Ceil(double check) {
    return ( check - int(check) ) ? check + 1 : check;
}