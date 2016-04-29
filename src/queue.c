#include "../inc/queue.h"

queue_t* init_queue() {
    queue_t *queue = NULL;

    queue = (queue_t *) malloc(sizeof(queue_t));
    queue->top = NULL;

    return queue;
}

void destroy_queue(queue_t *q) {
    node_t *node = NULL;    

    if (q == NULL) {
	printf("Queue is empty!\n");
	return;
    }
    
    node = pop(q);
    destroy_node(node);
    
    if (q->top == NULL) {
	free(q);
	q = NULL;
    }
    
    destroy_queue(q);
    return;
}

node_t* create_node(element_t e) {
    node_t *node = NULL;
    
    node = (node_t *) malloc(sizeof(node_t));
    node->c.string = (char *) malloc((MAX + 1) * sizeof(char));
    memset(node->c.string, '\0', (MAX + 1) * sizeof(char));
    node->c = e;
    node->down = NULL;

    return node;
}

void destroy_node(node_t *node) {
    if (node == NULL) {
	printf("Node is empty\n");
	return;
    }

    free(node->down);
    node->down = NULL;
    return;
}

void push(queue_t *q, element_t e) {
    node_t *node = NULL;
    
    if (q == NULL) {
	printf("Error: no queue was defined!\n");
	return;
    }
    
    node = create_node(e);

    if (node != NULL) {
	node->down = q->top;
	q->top = node;
    }
}

node_t* pop(queue_t *q) {
    node_t *node = NULL;

    if (q == NULL) {
	printf("Queue is empty!\n");
	return NULL;
    }

    node = q->top;
    q->top = q->top->down;
    node->down = NULL;
    
    return node;    
}

void print_queue(node_t *top) {
    if (top == NULL) {
	return;
    }

    printf("%d\n", top->c.x);
    printf("%s\n", top->c.string);

    print_queue(top->down);

    return;
}

size_t size_queue(queue_t *q) {
    node_t *node = NULL;
    size_t size = 0;

    if (q == NULL) {
	printf("Queue is empty!\n");
	return 0;
    }

    for (node = q->top; node != NULL; node = node->down) {
	size++;	
    }
    return size;
}

bool is_empty(queue_t *q) {
    if (q == NULL) {
	return TRUE;
    }
 
   return (size_queue(q) == 0 ? TRUE : FALSE);
}
