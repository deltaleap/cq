#include "config.h"

#ifndef MSG_LEN
#define MSG_LEN 8
#endif

#ifndef QUEUE_LEN
#define QUEUE_LEN 10
#endif


struct queue {
    int index;
    int len;
    int full;
    char msg[QUEUE_LEN][MSG_LEN];
};

void queue_init(struct queue *q);
void queue_add(struct queue *q, char *source);
void queue_pop(struct queue *q, char *dest);