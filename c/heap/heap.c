#include <assert.h>
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
    if (left < h->heapsize && h->array[left] > h->array[largest])
    {
        largest = left;
    }
    if (right < h->heapsize && h->array[right] > h->array[largest])
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

    heap->arraysize = arraysize;
    heap->heapsize = arraysize;

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

void heapsort(struct Heap *h, int *array, unsigned int arraysize)
{
    unsigned int i;

    build_max_heap(h, array, arraysize);
    for (i = arraysize; i > 1; i--)
    {
        swap(h->array, h->array+h->heapsize-1);
        h->heapsize--;
        maxheapify(h, 0);
    }
}

int heapmax(struct Heap *h)
{
    if (h->heapsize < 1)
    {
        return -1;  // error, underflow
    }

    return h->array[0];
}

int extract_heapmax(struct Heap *h)
{
    if (h->heapsize < 1)
    {
        return -1;  // error, underflow
    }

    int max = h->array[0];
    h->array[0] = h->array[h->heapsize];
    h->heapsize--;
    maxheapify(h, 0);

    return max;
}

void heap_increase(struct Heap *h, unsigned int i, int newkey)
{
    if (newkey < h->array[i])
    {
        return; // error, new key smaller than current key
    }

    h->array[i] = newkey;
    while (i > 0 && h->array[heap_parent(i)] < h->array[i])
    {
        swap(h->array+heap_parent(i), h->array+i);
        i = heap_parent(i);
    }
}

void heapinsert(struct Heap *h, int key)
{
    h->heapsize++;
    heap_increase(h, h->heapsize, key);
}

int main(int argc, char **argv)
{
    unsigned int i;

    int sorted[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    int unsorted[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, };
    struct Heap *h = malloc(sizeof(struct Heap));
    heapsort(h, unsorted, 10);
    for (i = 0; i < 10; i++)
    {
        assert(h->array[i] == sorted[i]);
    }


    build_max_heap(h, sorted, 10);
    assert(heapmax(h) == 9);
    extract_heapmax(h);
    assert(heapmax(h) == 8);
    heapinsert(h, 9);
    assert(heapmax(h) == 9);

    return 0;
}
