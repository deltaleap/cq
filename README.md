# CQ: Circular Queue

### how to use
- initialize
`c
    struct queue q;
    queue_init(&q);
`

- add item to the queue
`c
    char s[8] = "ciao";
    queue_add(&q, s);
`

- pop item out of the queue
`c
    char d[8];
    queue_pop(&q, d);
`

The size queue is determined at compile time, using the following macros:
`c
#define CQ_MSG_LEN 8
#define CQ_QUEUE_LEN 10
`

Make the CQ long enough to avoid overwrite of too old messages.
To make sure to not overwrite old message, add some checks before adding item:

`c
    char s[8] = "ciao";
    if(!q.full)
        queue_add(&q, s);
`