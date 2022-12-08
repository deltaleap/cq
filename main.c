#include <stdio.h>
#include <string.h>

#include "config.h"
#include "cq.h"

int main()
{
    printf("** Queue test **\n");
    char s[8] = "ciao";
    char d[8];
    
    struct queue q;
    queue_init(&q);

    printf("input: %s\n", s);
    printf("output: %s\n", d);
    
    queue_add(&q, s);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);
    queue_pop(&q, d);
    printf("input: %s\n", s);
    printf("output: %s\n", d);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);
    printf("\n");

    printf("let's add three item\n");
    memset(s, 'a', sizeof(s) - 1);
    printf("input: %s\n", s);
    queue_add(&q, s);
    memset(s, 'b', sizeof(s) - 1);
    printf("input: %s\n", s);
    queue_add(&q, s);
    memset(s, 'c', sizeof(s) - 1);
    printf("input: %s\n", s);
    queue_add(&q, s);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);

    printf("let's pop them\n");
    queue_pop(&q, d);
    printf("output: %s\n", d);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);
    queue_pop(&q, d);
    printf("output: %s\n", d);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);
    queue_pop(&q, d);
    printf("output: %s\n", d);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);
    queue_pop(&q, d);
    printf("output: %s\n", d);
    printf("queue len: %i\n", q.len);
    printf("queue index: %i\n", q.index);

    printf("\n");
    printf("test the queue overflow\n");
    queue_init(&q);
    printf("queue len: %i\n", q.len);

    for(int i = 0; i<40;i++)
    {
        memset(s, 'd', sizeof(s) - 1);
        queue_add(&q, s);
        printf("queue len: %i\n", q.len);
    }

    return 0;
}
