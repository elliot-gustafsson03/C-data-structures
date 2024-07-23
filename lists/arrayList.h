#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct arrayList {
  void *(*values);
  int capacity;
  int length;
} arrayList;

void initializeArrayList(arrayList *);
bool arrayListRepl(char, void *);
void freeArrayList(void *);

#endif
