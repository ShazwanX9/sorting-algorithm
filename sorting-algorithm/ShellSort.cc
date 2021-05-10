#include "ShellSort.hh"
#include "Ultility.hh"

ShellSort::ShellSort(int arr[], int size) {
    ShellSorting(arr, size);
}

void ShellSort::setGaps(std::vector<int>& gaps, int size, int year) {
    switch (year) {
        case 1959 : set1959Gaps(gaps, size); break;
        case 1960 : set1960Gaps(gaps, size); break;
        case 1963 : set1963Gaps(gaps, size); break;
        case 1965 : set1965Gaps(gaps, size); break;
        case 1971 : set1971Gaps(gaps, size); break;
        case 1973 : set1973Gaps(gaps, size); break;
        case 1982 : set1982Gaps(gaps, size); break;
        case 1986 : set1986Gaps(gaps, size); break;
        case 1992 : set1992Gaps(gaps, size); break;
        case 2001 : default: set2001Gaps(gaps);
    }
}

void ShellSort::set1959Gaps(std::vector<int>& gaps, int size) {
    for (int k = 0; size / Ultility::Pow(2, k) > 1; k++)
        gaps.push_back(size / Ultility::Pow(2, k));
    gaps.push_back(1);
}

void ShellSort::set1960Gaps(std::vector<int>& gaps, int size) {
    for (int k = 0; 2 * ( size / ( Ultility::Pow(2, k + 1) ) ) + 1 > 1; k++)
        gaps.push_back( 2 * ( size / ( Ultility::Pow(2, k + 1) ) ) + 1 );
    gaps.push_back(1);
}

void ShellSort::set1963Gaps(std::vector<int>& gaps, int size) {
    for (int k = 0; Ultility::Pow(2, k) - 1 > 1; k++)
        gaps.push_back( Ultility::Pow(2, k) - 1 );
    gaps.push_back(1);
}

void ShellSort::set1965Gaps(std::vector<int>& gaps, int size) {
    gaps.push_back(1);
    for (int k = 1; Ultility::Pow(2, k) + 1 > 1; k++)
        gaps.push_back( Ultility::Pow(2, k) + 1 );
}

void ShellSort::set1971Gaps(std::vector<int>& gaps, int size) {
    for (int i = 0, j = 0; Ultility::Pow(2, i) * Ultility::Pow(3, j) < size; i++, j++)
        gaps.push_back( Ultility::Pow(2, i) * Ultility::Pow(3, j) );
}

void ShellSort::set1973Gaps(std::vector<int>& gaps, int size) {
    for (int k = 0; (Ultility::Pow(3, k) - 1) / 2 < size / 3; k++)
        gaps.push_back( (Ultility::Pow(3, k) - 1) / 2 );
}

void ShellSort::set1982Gaps(std::vector<int>& gaps, int size) {
    gaps.push_back(1);
    for (int k = 1; Ultility::Pow(4, k) + 3 * Ultility::Pow(2, k - 1) + 1 < size; k++)
        gaps.push_back( Ultility::Pow(4, k) + 3 * Ultility::Pow(2, k - 1) + 1 );
}

void ShellSort::set1986Gaps(std::vector<int>& gaps, int size) {
    gaps.push_back(1);
    for (int k = 1, res = 1; res < size; k++) {
        (size % 2) ? // isOdd
            res = 9 * ( Ultility::Pow(2, k) - Ultility::Pow(2, k/2) ) + 1 :
            res = 8 * Ultility::Pow(2, k) - 6 * Ultility::Pow(2, (k + 1) / 2) + 1;
        gaps.push_back( res );
    }
}

void ShellSort::set1992Gaps(std::vector<int>& gaps, int size) {
    gaps.push_back(1);    
    for (int k = 0; Ultility::Ceil((9 * Ultility::Pow(9 / 4, k - 1) - 4) / 5) < size; k++)
        gaps.push_back( Ultility::Ceil((9 * Ultility::Pow(9 / 4, k - 1) - 4) / 5) );
}

void ShellSort::set2001Gaps(std::vector<int>& gaps) { 
    gaps = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
}

void ShellSort::ShellSorting(int arr[], int size, int year) {
    std::vector<int> gaps;
    setGaps(gaps, size, year);

    for (int k = 0; k < gaps.size(); k++) {
        int gap = gaps[k];
        for (int j = gap; j < size; j++) {
            int temp = arr[j];
            int k = j;

            while (k >= gap && arr[k - gap] > temp) {
                arr[k] = arr[k - gap];
                k -= gap;
            }
            arr[k] = temp;
        }
    }
}