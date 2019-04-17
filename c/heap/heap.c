#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

inline int heap_parent(int i)
{
    if (i == 0) return -1;
    return (i-1) / 2;
}

inline int heapleft(int i)
{
    return (i << 1) + 1;
}

inline int heapright(int i)
{
    return (i << 1) + 2;
}

void swap(int *i, int *j)
{
    // xor swap algorithm
    *i = *i ^ *j;
    *j = *j ^ *i;
    *i = *i ^ *j;
}

void maxheapify(struct Heap *h, unsigned int i)
{
    int left = heapleft(i);
    int right = heapright(i);
    int largest = i;
    if (left < h->size && h->array[left] > h->array[largest])
    {
        largest = left;
    }
    if (right < h->size && h->array[right] > h->array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(h->array+i, h->array+largest);
        maxheapify(h, largest);
    }
}

void build_max_heap(struct Heap *heap, int *array, unsigned int arraysize)
{
    if (!heap)
    {
        return;  // would be error
    }

    unsigned int i;

    heap->size = arraysize;

    for (i = 0; i < arraysize; i++)
    {
        heap->array[i] = array[i];
    }

    for (i = arraysize / 2; i != -1; i--)
    {
        maxheapify(heap, i);
    }    
}

void printarray(int *array, unsigned int size)
{
    unsigned int i;
    printf("{ ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("}\n");
}

int main(int argc, char **argv)
{
    int array[5] = { 0, 1, 2, 3, 4, };
    printarray(array, 5);
    struct Heap *h = malloc(sizeof(struct Heap));
    build_max_heap(h, array, 5);
    printarray(h->array, 5);
    return 0;
}
