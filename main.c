#include "linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printWelcome();
void repl();

linkedList list;

int main() {
  initializeList(&list);

  printWelcome();
  repl();

  return 0;
}

void printWelcome() {
  char *welcomeMessage =
      "Welcome to list REPL. Type 'h' to get a list of all commands";
  printf("%s\n", welcomeMessage);

  char *letter = welcomeMessage;
  while (*letter != '\0') {
    putchar('-');
    letter++;
  }
  printf("\n\n");
}

void quitCommand(bool *q);
void invalidCommand();
void helpCommand();
void insertCommand();
void printCommand();

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void repl() {
  bool terminated = false;
  int command;

  while (!terminated) {
    putchar('>');
    fflush(stdout);

    command = getchar();

    switch (command) {
    case 'q':
      quitCommand(&terminated);
      break;
    case 'h':
      helpCommand();
      clearInputBuffer();
      break;
    case 'i':
      insertCommand();
      clearInputBuffer();
      break;
    case 'p':
      printCommand();
      clearInputBuffer();
      break;
    default:
      invalidCommand();
      clearInputBuffer();
      break;
    }
  }
}

void quitCommand(bool *q) {
  printf("Terminating. Thank you for using list REPL!\n\n");
  *q = true;
}

void helpCommand() {
  printf("h (help)\t- Displays a list of all commands\n");
  printf("i (insert)\t- Lets you insert a new value into the list\n");
  printf("p (print)\t- Prints the length and content of the list\n");
  printf("q (quit)\t- Terminates the program \n\n");
}

void invalidCommand() {
  printf("The given command is invalid. Type 'h' to see a list of all "
         "commands.\n\n");
}

void insertCommand() {
  int n;
  printf("Number to insert: ");
  scanf("%d", &n);

  int *value = (int *)malloc(sizeof(int));
  *value = n;

  insert(&list, value);
  printf("\n");
}

void printCommand() {
  printList(&list);
  printf("\n\n");
}
