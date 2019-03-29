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

void free_sll(struct SLinkedList *sll);

int sll_is_empty(struct SLinkedList *sll);

void sll_insert(int value, struct SLinkedList *sll);

int sll_remove(int key, struct SLinkedList *sll);

struct SLinkedList *init_sll(void);

/* test declarations */
int test_new_list_is_empty(void);

int test_able_to_insert(void);

int test_remove_from_empty(void);

int test_remove_head(void);

int test_remove_from_body(void);

int test_remove_key_does_not_exist(void);
