#include "linkedList.h"
#include <stdio.h>
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

void quitCommand() {
  printf("Terminating. Thank you for using list REPL!\n\n");
}

void invalidCommand() {
  printf("The given command is invalid. Type 'h' to see a list of all "
         "commands.\n\n");
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void repl() {
  int command;

  while (true) {
    putchar('>');
    fflush(stdout);

    command = getchar();

    if (command == 'q') {
      quitCommand();
      return;
    }

    bool valid = linkedListRepl(command, &list);
    if (!valid) {
      invalidCommand();
    }

    clearInputBuffer();
  }
}
