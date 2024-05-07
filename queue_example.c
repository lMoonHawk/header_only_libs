#define DARRAY_IMPLEMENTATION
#include "darray.h"
#define QUEUE_IMPLEMENTATION
#include "queue.h"

// For testing
int check_seq(int *arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        if (arr[i] + 1 != arr[i+1]) return 0;
    }
    return 1;
}

// Custom queue item
typedef struct {
    char *str;
    int d;
} My_struct;

// Debug - Print method for this type
void print_mystruct(void* q_item) {
    My_struct it = *(My_struct*) q_item;
    printf("{str=\"%s\", d=%d}\n", it.str, it.d); 
}

int main() {
    Queue q = q_create(sizeof(int));

    int pushes[] = {3, 5, 10, 3};
    int pops[] = {2, 1, 15, 3};
    int popped[256];

    int push_seq = 0;
    int pop_seq = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < pushes[i]; ++j) {
            q_push(q, push_seq);
            push_seq++;
        }
        for (int j = 0; j < pops[i]; ++j) {
            q_pop(q, &popped[pop_seq]);
            pop_seq++;
        }
    }

    printf("Popped correctly?: %d\n", check_seq(popped, pop_seq));
    q_free(q);

    // 
    Queue q_struct = q_create(sizeof(My_struct));
    
    q_push(q_struct, ((My_struct){"foo", 3}));
    q_push(q_struct, ((My_struct){"bar", 42}));
    q_push(q_struct, ((My_struct){"baz", 98}));
    q_push(q_struct, ((My_struct){"foobarbaz", __INT_MAX__}));

    q_print(q_struct, 2, print_mystruct);
    q_free(q_struct);
}