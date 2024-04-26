#include <stdio.h>

#define DARRAY_IMPLEMENTATION
#include "darray.h"
#define PQUEUE_IMPLEMENTATION
#include "pqueue.h"

int cmpint(const void* p1, const void* p2) {
    int v1 = *(int*)p1;
    int v2 = *(int*)p2;
    return (v1 == v2) ? 0 : 2 * (v1 > v2) - 1;
}

int main() {
    Pq ht = pq_create(sizeof(int), cmpint);

    // Push values
    int seed = 42;
    for (int i = 0; i < 15; ++i) {
        seed = (seed + 11) % 17;
        printf("Pushed: %2d\n", seed);
        pq_push(ht, seed);
    }

    // Display highest priority item:
    printf("\n");
    const int* peeked = pq_peek(ht);
    printf("Peeked: %d\n\n", *peeked);


    // Pop elements from the queue
    while(pq_length(ht)) {
        int p;
        pq_pop(ht, &p);
        printf("Popped: %2d\n", p);
    }
}