#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap_sort.h"


// ................

size_t left(size_t index) {
    return index * 2 + 1;
}
size_t right(size_t index) {
    return index * 2 + 2;
}
size_t parent(size_t index) {
    return (index - 1) / 2;
}

bool has_left(size_t size, size_t index) {
    return left(index) < size;
}
bool has_right(size_t size, size_t index) {
    return right(index) < size;
}
bool has_parent(size_t index) {
    return index > 0;
}

Element get(Element* array, size_t size, size_t index) {
    if (index >= size) {
        return ELEMENT_NULL;
    }

    return array[index];
}

void swap_at(Element* array, size_t i, size_t j) {
    Element temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
size_t maximum_child(Element* array, size_t size, size_t cur) {
    size_t left_child = left(cur);

    if (!has_right(size, cur)) {
        return left_child;
    }

    size_t right_child = right(cur);

    return element_compare(get(array, size, left_child), get(array, size, right_child)) >= 0
        ? left_child
        : right_child;
}


void sift_down_at(Element * arr, size_t size, size_t index)
{
    size_t curr = index;

    while (has_left(size, curr))
    {
        size_t maxChild = maximum_child(arr, size, curr);

        if (element_compare(get(arr, size, curr), get(arr, size, maxChild)) >= 0) { return; }

        swap_at(arr, curr, maxChild);
        curr = maxChild;
    }
}
void heapify(Element * arr, size_t size)
{
    if (size < 2) { return; }

    for (size_t i = parent(size - 1); i > 0; i--)
    {
        sift_down_at(arr, size, i);
    }
}

// ................

void heapSort(Element * array, size_t size)
{
    size_t heapSize = size;
    heapify(array, heapSize);

    for (size_t i = 0; i < size; i++)
    {
        swap_at(array, 0, heapSize - 1);
        heapSize--;
        sift_down_at(array, heapSize, 0);
    }
}

//// <!>
