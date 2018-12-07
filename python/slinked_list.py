class Node(object):
    def __init__(self, value, _next):
        self.value = value
        self.next = _next

    def __str__(self):
        return str(self.value)

class SLinkedList(object):
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def insert(self, value):
        new = Node(value, self.head)
        self.head = new

    def remove(self, key):
        # fast track empty list
        if self.head is None:
            return False

        # fast track if we're removing head
        if self.head.value == key:
            self.head = self.head.next
            return True

        current = self.head.next
        previous = self.head

        while current is not None:
            if current.value == key:
                previous.next = current.next
                return True
            previous = current
            current = current.next

        return False

    def __iter__(self):
        if self.head is None:
            return

        current = self.head
        while current is not None:
            yield current
            current = current.next

    def __str__(self):
        return "[" + ", ".join(str(n) for n in self) + "]"
