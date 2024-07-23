#include "arrayList.h"
#include <stdio.h>

const int MARGIN = 5;

void initializeArrayList(arrayList *list) {
  list->values = (void *)malloc(MARGIN * sizeof(void *));
  list->capacity = MARGIN;
  list->length = 0;
}

static void increaseCapacity(arrayList *list) {
  list->capacity += MARGIN;
  list->values = realloc(list->values, list->capacity * sizeof(void *));
}

static void insert(arrayList *list, void *value) {
  if (list->length == list->capacity) {
    increaseCapacity(list);
  }

  list->values[list->length] = value;
  list->length++;
}

static int getValue(arrayList *list, int index) {
  if (index < 0 || index >= list->length) {
    return 0;
  }

  return *((int *)list->values[index]);
}

static void printList(arrayList *list) {
  printf("Length of list: %d, with capacity: %d\n", list->length,
         list->capacity);
  putchar('[');

  if (list->length > 0) {
    printf("%d", *(int *)list->values[0]);
  }

  for (int i = 1; i < list->length; i++) {
    printf(", %d", *(int *)list->values[i]);
  }

  putchar(']');
}

void freeArrayList(void *list) {
  arrayList *l = (arrayList *)list;
  for (int i = 0; i < l->length; i++) {
    free(l->values[i]);
  }
  free(l->values);

  initializeArrayList(l);
}

// REPL COMMANDS

static void helpCommand() {
  printf("h (help)\t- Displays a list of all commands\n");
  printf("i (insert)\t- Lets you insert a new value into the list\n");
  printf("g (get)\t\t- Retrieve the value at a certain index\n");
  printf("p (print)\t- Prints the length and content of the list\n");
  printf("q (quit)\t- Terminates the program \n\n");
}

static void insertCommand(arrayList *list) {
  int n;
  printf("Number to insert: ");
  scanf("%d", &n);

  int *value = (int *)malloc(sizeof(int));
  *value = n;

  insert(list, value);
  printf("\n");
}

static void getCommand(arrayList *list) {
  int index;
  printf("Index to retrieve: ");
  scanf("%d", &index);

  printf("The value at index %d is: %d\n\n", index, getValue(list, index));
}

static void printCommand(arrayList *list) {
  printList(list);
  printf("\n\n");
}

bool arrayListRepl(char command, void *list) {
  switch (command) {
  case 'h':
    helpCommand();
    break;
  case 'i':
    insertCommand(list);
    break;
  case 'g':
    getCommand(list);
    break;
  case 'p':
    printCommand(list);
    break;
  default:
    return false;
  }

  return true;
}
