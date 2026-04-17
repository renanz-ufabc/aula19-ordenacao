#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>


struct BinaryHeap
{
    Element * array;
    size_t capacity;
    size_t size;
};


BinaryHeap * bheap_create(size_t capacity)
{
    BinaryHeap * bheap = malloc(sizeof(BinaryHeap));

    bheap->array = malloc(capacity * sizeof(Element));
    bheap->capacity = capacity;
    bheap->size = 0;

    return bheap;
}
void bheap_destroy(BinaryHeap * bheap)
{
    free(bheap->array);
    free(bheap);
}

// ................

size_t left(size_t index)
{
    return 2 * index + 1;
}
size_t right(size_t index)
{
    return 2 * index + 2;
}
size_t parent(size_t index)
{
    return (index - 1) / 2;
}

bool has_left(BinaryHeap * bheap, size_t index)
{
    return left(index) < bheap->size;
}
bool has_right(BinaryHeap * bheap, size_t index)
{
    return right(index) < bheap->size;
}
bool has_parent(size_t index)
{
    return index > 0;
}

Element get_left(BinaryHeap * bheap, size_t index)
{
    if (!has_left(bheap, index)) { return ELEMENT_NULL; }

    return bheap->array[left(index)];
}
Element get_right(BinaryHeap * bheap, size_t index)
{
    if (!has_right(bheap, index)) { return ELEMENT_NULL; }

    return bheap->array[right(index)];
}
Element get_parent(BinaryHeap * bheap, size_t index)
{
    if (!has_parent(index)) { return ELEMENT_NULL; }

    return bheap->array[parent(index)];
}
Element get(BinaryHeap * bheap, size_t index)
{
    if (index >= bheap->size) { return ELEMENT_NULL; }

    return bheap->array[index];
}

void swap_at(BinaryHeap * bheap, size_t i, size_t j)
{
    Element aux = bheap->array[i];
    bheap->array[i] = bheap->array[j];
    bheap->array[j] = aux;
}
void sift_up(BinaryHeap * bheap)
{
    size_t curr = bheap->size - 1;

    while (has_parent(curr) && element_compare(get(bheap, curr), get_parent(bheap, curr)) > 0)
    {
        swap_at(bheap, curr, parent(curr));
        curr = parent(curr);
    }
}
size_t maximum_child(BinaryHeap * bheap, size_t curr)
{
    size_t leftChild = left(curr);

    if (!has_right(bheap, curr)) { return leftChild; }

    size_t rightChild = right(curr);

    return element_compare(get(bheap, leftChild), get(bheap, rightChild)) >= 0 
        ? leftChild 
        : rightChild;
}
void sift_down(BinaryHeap * bheap)
{
    size_t curr = 0;

    while (has_left(bheap, curr))
    {
        size_t maxChild = maximum_child(bheap, curr);

        if (element_compare(get(bheap, curr), get(bheap, maxChild)) >= 0) { return; }

        swap_at(bheap, curr, maxChild);
        curr = maxChild;
    }
}

// ................

void bheap_insert(BinaryHeap * bheap, Element element)
{
    if (bheap_is_full(bheap)) { return; }

    bheap->array[bheap->size] = element;
    bheap->size++;
    sift_up(bheap);
}
Element bheap_extract(BinaryHeap * bheap)
{
    if (bheap->size == 0) { return ELEMENT_NULL; }

    Element result = bheap->array[0];

    bheap->array[0] = bheap->array[bheap->size - 1];
    bheap->size--;
    sift_down(bheap);

    return result;
}
Element bheap_peek(BinaryHeap * heap)
{
    if (heap->size == 0) { return ELEMENT_NULL; }

    return heap->array[0];
}

size_t bheap_size(BinaryHeap * bheap)
{
    return bheap->size;
}
bool bheap_is_empty(BinaryHeap * bheap)
{
    return bheap->size == 0;
}
bool bheap_is_full(BinaryHeap * heap)
{
    return heap->size == heap->capacity;
}

void bheap_print(BinaryHeap * bheap)
{
    for (size_t i = 0; i < bheap->size; i++) 
    {
        element_print_sp(bheap->array[i]);
    }
    printf("\n");
}
