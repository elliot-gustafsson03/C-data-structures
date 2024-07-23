#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void initializeList(linkedList *list) {
  list->head = NULL;
  list->last = NULL;
  list->length = 0;
}

node *createNode(void *value) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

void insert(linkedList *list, void *value) {
  node *newNode = createNode(value);

  if (list->length == 0) {
    list->head = newNode;
    list->last = newNode;
  } else {
    list->last->next = newNode;
    list->last = newNode;
  }

  list->length++;
}

void printList(linkedList *list) {

  printf("Length of list: %d\n", list->length);
  putchar('[');

  if (list->length > 0) {
    int firstNum = *(int *)list->head->value;
    printf("%d", firstNum);

    node *nextNode = list->head->next;
    while (nextNode != NULL) {
      int nextNum = *(int *)nextNode->value;
      printf(" -> %d", nextNum);

      nextNode = nextNode->next;
    }
  }

  printf("]");
}

void freeList(linkedList *list) {
  node *current = list->head;
  while (current != NULL) {
    node *next = current->next;
    free(current->value);
    free(current);
    current = next;
  }

  initializeList(list);
}

// REPL COMMANDS

void helpCommand() {
  printf("h (help)\t- Displays a list of all commands\n");
  printf("i (insert)\t- Lets you insert a new value into the list\n");
  printf("p (print)\t- Prints the length and content of the list\n");
  printf("q (quit)\t- Terminates the program \n\n");
}

void insertCommand(linkedList *list) {
  int n;
  printf("Number to insert: ");
  scanf("%d", &n);

  int *value = (int *)malloc(sizeof(int));
  *value = n;

  insert(list, value);
  printf("\n");
}

void printCommand(linkedList *list) {
  printList(list);
  printf("\n\n");
}

bool linkedListRepl(char command, linkedList *list) {
  switch (command) {
  case 'h':
    helpCommand();
    break;
  case 'i':
    insertCommand(list);
    break;
  case 'p':
    printCommand(list);
    break;
  default:
    return false;
    break;
  }

  return true;
}
