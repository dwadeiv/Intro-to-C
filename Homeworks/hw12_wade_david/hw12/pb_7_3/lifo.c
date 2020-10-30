#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

struct _lifo {
  unsigned capacity;
  unsigned top;
  void * data[1];
};

lifo * newLifo(int capacity) {
  lifo * q;
  if (capacity < 1) return NULL;
  
  /* allocate one chunk of memory */
  q = malloc(sizeof(lifo) +
             ((capacity-1) * sizeof(void *)));
  if (!q) return NULL;
  q->capacity = (unsigned) capacity;
  q->top = 0;
  return q;
}

void deleteLifo(lifo * q) {
  free(q);
}

int isEmptyLifo(lifo const * q) {
  if (!q) return 1;
  return q->top == 0;
}

int putLifo(lifo * q, void * e) {
  if (!q) return -1;
  if (q->top == q->capacity) /* full? */
    return -1;
  q->data[q->top] = e;
  q->top ++;
  return 0;
}

int getLifo(lifo * q, void ** e) {
  if (!q) return -1;
  if (!e) return -1;
  if (isEmptyLifo(q)) {
    *e = NULL;
    return -2;
  }
  q->top--;
  *e = q->data[q->top];
  return 0;
}

int sizeLifo(lifo const * q) {
  return(q->top);
}

int printLifo(lifo const * q, printFn f) {
  unsigned i, cnt;
  if (!q) return -1;
  if (!f) return -1;
  cnt = 1;
  for (i = 1; i <= q->top; i ++) {
    printf(" %d:", cnt);
    f(q->data[i-1]);
    cnt++;
  }
  printf("\n");
  return 0;
}

int peekLifo(lifo const * q, void ** e) {
  if(!q || !e) return -1;
  if(isEmptyLifo(q)) {
    *e = NULL;
    return -2;
  }
  *e = q->data[q->top-1];
  return 0;
}
