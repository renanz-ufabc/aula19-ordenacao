#include "selection_sort.h"


void selectionSort(Element * arr, int n)
{
    if (n < 2) { return; }

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) { minIndex = j; }
        }

        if (i != minIndex) { element_swap(arr+i, arr+minIndex); }
    }
}
