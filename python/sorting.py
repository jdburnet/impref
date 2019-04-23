def swap(seq, i, j):
    if i == j:
        return
    seq[i] = seq[i] + seq[j]
    seq[j] = seq[i] - seq[j]
    seq[i] = seq[i] - seq[j]


def insertion_sort(seq):
    for i in range(1, len(seq)):
        j = i
        while (j > 0) and (seq[j] < seq[j-1]):
            swap(seq, j, j - 1)
            j -= 1


def mergesort(seq):
    if len(seq) <= 1:
        return

    mid = len(seq) // 2
    left = seq[:mid]
    right = seq[mid:]

    mergesort(left)
    mergesort(right)

    i = j = k = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            seq[k] = left[i]
            i += 1
        else:
            seq[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        seq[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        seq[k] = right[j]
        j += 1
        k += 1


def partition(seq, l, h):
    firsthigh = l
    p = h

    for i in range(l, h):
        if seq[i] < seq[p]:
            swap(seq, i, firsthigh)
            firsthigh += 1
    swap(seq, p, firsthigh)

    return firsthigh


def _quicksort(seq, l, h):
    if l >= h:
        return
    p = partition(seq, l, h)
    _quicksort(seq, l, p - 1)
    _quicksort(seq, p + 1, h)

def quicksort(seq):
    return _quicksort(seq, 0, len(seq) - 1)
