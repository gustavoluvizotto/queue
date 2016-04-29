#ifndef QUEUE_H_
#define QUEUE_H_

/* FIFO structure */

#include "common.h"

#define MAX 10

#pragma pack (push, 1)
typedef struct {
    char *string;
    uint32_t x;
} element_t;
#pragma pack (pop)

typedef struct node_s {
    element_t c;
    struct node_s *down;
} node_t;

typedef struct {
    node_t *top;
} queue_t;

void push(queue_t*, element_t);
node_t* pop(queue_t*);
queue_t* init_queue();
void destroy_queue(queue_t*);
node_t* create_node(element_t);
void destroy_node(node_t*);
void print_queue(node_t*);
size_t size_queue(queue_t*);
bool is_empty(queue_t*);

#endif
