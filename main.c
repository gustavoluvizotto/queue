#include "inc/common.h"
#include "inc/queue.h"

int main() {
    FILE *fp = NULL;
    content_t *content = NULL;
    
    queue_t *queue = NULL;    
    element_t e;
    node_t *node = NULL;

    /*---------FILE HANDLER-----------------------------------*/
    fp = fopen("resources/test.txt", "r+");
    if (fp == NULL) {
	printf("Error to open\n");
	return 0;
    }

    content = (content_t *) malloc(sizeof(content_t));
    if (fread(content, sizeof(content_t), 1, fp) != 1) {
	printf("Could not read the file\n");
	return 0;
    }

    printf("first 4bytes: %x\n", content->t1);
    printf("1byte next: %c\n", content->c);
    printf("1byte next: %x\n", content->t2);

    printf("%lu\n",sizeof(content_t));

    free(content);
    content = NULL;
    fclose(fp);
    printf("-----------\n");
    /*---------------------------------------------------------*/

    queue = init_queue();
    
    printf("Empty: %d\n", is_empty(queue));
    
    e.x = 3;
    e.string = (char *) malloc((MAX + 1) * sizeof(char));
    memset(e.string, '\0', (MAX + 1) * sizeof(char));
    memcpy(e.string, "TEST", strlen("TEST") * sizeof(char));
    push(queue, e);
    print_queue(queue->top);

    printf("Empty: %d\n", is_empty(queue));    

    e.x = 5;
    push(queue, e);
    
    e.x = 7;
    push(queue, e);

    print_queue(queue->top);

    printf("Size: %zu\n", size_queue(queue));   

    node = pop(queue);
    
    printf("Size: %zu\n", size_queue(queue));
    
    printf("%d\n", node->c.x);
    printf("%s\n", node->c.string);    
    
    destroy_queue(queue);
    destroy_node(node);

    printf("Empty: %d\n", is_empty(queue));    

    return 0;
}
