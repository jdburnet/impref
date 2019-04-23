from collections import namedtuple
import random

import pytest
from .. import sorting


Lists = namedtuple("TestList", "sorted unsorted")


@pytest.fixture
def lists():
    _sorted = [0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9]
    unsorted = random.sample(_sorted, len(_sorted))
    return Lists(_sorted, unsorted)


def test_insertion_sort(lists):
    sorting.insertion_sort(lists.unsorted)
    assert lists.sorted == lists.unsorted


def test_mergesort(lists):
    sorting.mergesort(lists.unsorted)
    assert lists.sorted == lists.unsorted


def test_quicksort(lists):
    sorting.quicksort(lists.unsorted)
    assert lists.sorted == lists.unsorted
