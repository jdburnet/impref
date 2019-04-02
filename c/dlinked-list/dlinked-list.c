#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dlinked-list.h"

struct DLinkedList *init_dll(void)
{
    struct DLinkedList *dll = malloc(sizeof(struct DLinkedList));
    struct Node *head = malloc(sizeof(struct Node));
    head->next = NULL;
    head->prev = NULL;
    dll->head = head;
    return dll;
}

void clean(struct DLinkedList *dll)
{
    struct Node *n = dll->head;

    while (n)
    {
        n = n->next;
        free(n->prev);
    }

    free(dll);
}

int empty(struct DLinkedList *dll)
{
    return !!dll->head;
}

int insert(int value, struct DLinkedList *dll)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->key = value;
    n->next = dll->head;
    dll->head = n;
    n->prev = NULL;
    return 0;
}

struct Node *search(int value, struct DLinkedList *dll)
{
    struct Node *n = dll->head;

    while (n && n->key != value)
    {
        n = n->next;
    }

    return n;
}


int del(int value, struct DLinkedList *dll)
{
    if (empty(dll))
    {
        return -1;
    }

    struct Node *n = search(value, dll);
    if (!n)
    {
        return -1;
    }

    n->next->prev = n->prev;
    n->prev->next = n->next;
    free(n);
    return 0;
}

int main(int argc, char **argv)
{
    struct DLinkedList *dll = init_dll();

    insert(42, dll);
    assert(dll->head->key == 42);
    insert(74, dll);
    insert(128, dll);
    assert(dll->head->key == 128);
    del(42, dll);
    del(128, dll);
    del(74, dll);
    int ret = del(74, dll);
    assert(ret == -1);
    assert(empty(dll));
}
