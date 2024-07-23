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

void initializeLinkedList(linkedList *);
bool linkedListRepl(char, void *);
void freeLinkedList(void *);

#endif
