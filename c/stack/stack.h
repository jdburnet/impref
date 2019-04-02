struct Stack {
    int top;
    int size;
    int arr[];
};

struct Stack *init(int size);

int empty(struct Stack *stack);

int full(struct Stack *stack);

int push(int val, struct Stack *stack);

int pop(struct Stack *stack);
