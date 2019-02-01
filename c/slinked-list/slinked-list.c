#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../testing/testing.h"

static const int FAIL = 0;
static const int SUCCESS = 1;

struct Node
{
    int value;
    struct Node *next;
};

struct SLinkedList
{
    struct Node *head;
};

void free_sll(struct SLinkedList *sll)
{
    struct Node *node;

    while ((node = sll->head))
    {
        sll->head = sll->head->next;
        free(node);
    }

    free(sll);
};

int sll_is_empty(struct SLinkedList *sll)
{
    return !!sll->head;
};

void sll_insert(int value, struct SLinkedList *sll)
{
    struct Node *node = malloc(sizeof(struct Node));

    node->value = value;
    node->next = sll->head;
    sll->head = node;
};

int sll_remove(int key, struct SLinkedList *sll)
{
    if (sll_is_empty(sll))
    {
        return FAIL;
    }

    if (sll->head->value == key)
    {
        free(sll->head);
        sll->head = sll->head->next;
        return SUCCESS;
    };

    struct Node *current = sll->head->next;
    struct Node *previous = sll->head;

    while (current)
    {
        if (current->value == key)
        {
            previous->next = current->next;
            return SUCCESS;
        }
        previous = current;
        current = current->next;
    }

    return FAIL;
};


struct SLinkedList *init_sll(void)
{
    struct SLinkedList *sll = malloc(sizeof(struct SLinkedList));
    sll->head = NULL;
    return sll;
}

int main(int argc, char **argv)
{
    struct SLinkedList *sll = init_sll();

    sll_insert(0, sll);
    assert(sll->head->value == 0);
    free_sll(sll);
    return 0;
};
