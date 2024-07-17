#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct node {
  void *value;
  struct node *next;
} node;

typedef struct linkedList {
  node *head;
  node *last;
  int length;
} linkedList;

void initializeList(linkedList *list);
void insert(linkedList *list, void *value);
void printList(linkedList *list);
void freeList(linkedList *list);

#endif
