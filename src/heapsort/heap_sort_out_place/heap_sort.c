#include "heap_sort.h"
#include "binary_heap.h"


void heapSort(Element * array, size_t n)
{
    BinaryHeap * heap = bheap_create(n);

    for (size_t i = 0; i < n; i++) { bheap_insert(heap, array[i]); }
    
    for (size_t i = n - 1;  i < n && i >= 0; i--)
    {
        array[i] = bheap_extract(heap);
    }
}
