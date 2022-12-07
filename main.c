#include <stdio.h>
#include <string.h>

#define MSG_LEN 8
#define QUEUE_LEN 10

struct queue {
    int index;
    int len;
    int full;
    char msg[QUEUE_LEN][MSG_LEN];
};

void
queue_init(struct queue *q)
{
    q->index = 0;
    q->len = 0;
    q->full = 0;
}

void
queue_add(struct queue *q, char *source)
{
    int index = q->index;
    int len = q->len++;
    int starting_pointer = 0;

    if( (index + len) > QUEUE_LEN - 1)
    {
        starting_pointer = index + len - QUEUE_LEN;
    } else {
        starting_pointer = index + len;
    }
    printf("index = %i, len = %i, starting pointer = %i\n", index, len, starting_pointer);
    printf("p: %p\n", q->msg[starting_pointer]);

    memcpy(&(q->msg[starting_pointer]), source, MSG_LEN);

    if (len == QUEUE_LEN)
    {
        q->full = 1;
        q->len--;
    }
}

void
queue_pop(struct queue *q, char *dest)
{
    if (q->len == 0)
        return;

    int index = q->index++;
    memcpy(dest, &(q->msg[index]), MSG_LEN);
    q->len--;

    if(q->full)
        q->full = 0;
}

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
