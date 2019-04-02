struct Queue {
    int head;
    int tail;
    int size;
    int arr[];
};

struct Queue *init(int size);

int empty(struct Queue *queue);

int full(struct Queue *queue);

int wouldwrap(int location, int size);

int enqueue(int val, struct Queue *queue);

int dequeue(struct Queue *queue);
