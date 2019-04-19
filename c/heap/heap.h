#define MAXHEAP 1000

struct Heap {
    unsigned int arraysize;
    unsigned int heapsize;
    int array[MAXHEAP];
};

extern inline int heap_parent(int i);
extern inline int heapleft(int i);
extern inline int heapright(int i);
void swap(int *i, int *j);
void maxheapify(struct Heap *h, unsigned int i);
void build_max_heap(struct Heap *heap, int *array, unsigned int arraysize);
void printarray(int *array, unsigned int size);
void heapsort(struct Heap *h, int *array, unsigned int arraysize);
