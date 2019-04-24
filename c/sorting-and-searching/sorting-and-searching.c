#include <assert.h>
#include "sorting-and-searching.h"

int binsearch(int *arr, int low, int high, int key)
{
    if (high < low) return -1; // key not in arr

    int mid = low + ((high - low) / 2);
    if (arr[mid] > key) return binsearch(arr, low, mid - 1, key);
    if (arr[mid] < key) return binsearch(arr, mid + 1, high, key);
    return mid;
}

int main(int argc, char **argv)
{
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    assert(binsearch(arr, 0, 10, 9) == 9);
    assert(binsearch(arr, 0, 10, 42) == -1);

    return 0;
}
