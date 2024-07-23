#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdbool.h>

typedef struct node {
  void *value;
  struct node *next;
} node;

typedef struct linkedList {
  node *head;
  node *last;
  int length;
} linkedList;

bool linkedListRepl(char, linkedList *);
void initializeList(linkedList *);
void insert(linkedList *, void *);
void printList(linkedList *);
void freeList(linkedList *);

#endif
