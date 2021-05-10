// https://en.wikipedia.org/wiki/Shellsort

#include <vector>

#ifndef _SHELL_SORT
#define _SHELL_SORT

class ShellSort {
    void ShellSorting(int[], int, int = 2001);
    void setGaps(std::vector<int>&, int, int = 2001);

    void set1959Gaps(std::vector<int>&, int); // Original Shell Gaps
    void set1960Gaps(std::vector<int>&, int); // Frank & Lazarus Gaps
    void set1963Gaps(std::vector<int>&, int); // Hibbard Gaps
    void set1965Gaps(std::vector<int>&, int); // Papernov & Stasevich Gaps
    void set1971Gaps(std::vector<int>&, int); // Pratt Gaps
    void set1973Gaps(std::vector<int>&, int); // Knuth Gaps refer Pratt Gaps
    // void set1985Gaps(std::vector<int>&, int); // Incerpi & Sedgewick, Knuth Gaps
    void set1982Gaps(std::vector<int>&, int); // Sedgewick Gaps
    void set1986Gaps(std::vector<int>&, int); // Sedgewick Gaps
    // void set1991Gaps(std::vector<int>&, int); // Gonnet & Baeza-Yates Gaps
    void set1992Gaps(std::vector<int>&, int); // Tokuda Gaps
    void set2001Gaps(std::vector<int>&); // Ciura Gaps

    public:
        ShellSort(int[], int);
};

#endif