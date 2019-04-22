def swap(seq, i, j):
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
