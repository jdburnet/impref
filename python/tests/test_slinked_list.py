import pytest

from .. import slinked_list as sll

def test_node_str():
    assert str(sll.Node(1, None)) == "1"

@pytest.fixture
def linkedlist():
    """returns an empty linked list"""
    return sll.SLinkedList()

def test_is_empty(linkedlist):
    assert linkedlist.is_empty()

def test_insert(linkedlist):
    linkedlist.insert(1)
    assert linkedlist.head.value == 1

def test_inserts_to_front(linkedlist):
    linkedlist.insert(1)
    linkedlist.insert(2)
    assert linkedlist.head.value == 2

def test_remove_from_empty(linkedlist):
    assert not linkedlist.remove(1)

def test_remove_head(linkedlist):
    linkedlist.insert(1)
    assert linkedlist.remove(1)

def test_remove_from_body(linkedlist):
    linkedlist.insert(1)
    linkedlist.insert(2)
    linkedlist.insert(3)

    assert linkedlist.remove(1)

def test_remove_removes(linkedlist):
    linkedlist.insert(1)
    linkedlist.insert(2)
    linkedlist.insert(3)

    linkedlist.remove(2)
    assert linkedlist.head.next.value == 1

def test_remove_key_does_not_exist(linkedlist):
    linkedlist.insert(1)
    linkedlist.insert(2)

    assert not linkedlist.remove(4)

def test_linked_list_str(linkedlist):
    linkedlist.insert(1)
    linkedlist.insert(2)
    linkedlist.insert(3)

    assert str(linkedlist) == "[3, 2, 1]"

def test_empty_linked_list_str(linkedlist):
    assert str(linkedlist) == "[]"
