struct Node {
  int key;
  struct Node *next;
  struct Node *prev;
};

struct DLinkedList {
    struct Node *head;
};

struct DLinkedList *init_dll(void);

void clean(struct DLinkedList *dll);

int empty(struct DLinkedList *dll);

int insert(int value, struct DLinkedList *dll);

int del(int value, struct DLinkedList *dll);

struct Node *search(int value, struct DLinkedList *dll);
