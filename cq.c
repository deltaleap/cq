#include "cq.h"
#include <string.h>

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