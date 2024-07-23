#include "lists/arrayList.h"
#include "lists/linkedList.h"
#include <stdio.h>
#include <unistd.h>

typedef struct listInterface {
  bool (*repl)(char, void *);
  void (*freeList)(void *);
} listInterface;

void printWelcome() {
  char *welcomeMessage =
      "\nWelcome to list REPL! Please start by selecting a list type";
  printf("%s\n", welcomeMessage);

  char *letter = welcomeMessage;
  while (*letter != '\0') {
    putchar('-');
    letter++;
  }
  printf("\n\n");
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void repl(void *, listInterface *);

void startRepl() {
  printf("(1) Array list\n");
  printf("(2) Linked list\n");

  int choice;
  bool validChoice;

  listInterface li;
  void *list;

  while (!validChoice) {
    printf("\nChoose list type: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("\nYou have chosen Array list. Type 'h' to see a list of possible "
             "commands\n\n");

      arrayList al;
      initializeArrayList(&al);
      li.repl = arrayListRepl;
      li.freeList = freeArrayList;
      list = &al;

      validChoice = true;
      break;

    case 2:
      printf("\nYou have chosen Linked list. Type 'h' to see a list of "
             "possible commands\n\n");

      linkedList ll;
      initializeLinkedList(&ll);
      li.repl = linkedListRepl;
      li.freeList = freeLinkedList;
      list = &ll;

      validChoice = true;
      break;

    default:
      printf("Invalid choice. Please pick one of the above\n");
    }

    clearInputBuffer();
  }

  repl(list, &li);
}

void quitCommand() {
  printf("Terminating. Thank you for using list REPL!\n\n");
}

void invalidCommand() {
  printf("The given command is invalid. Type 'h' to see a list of all "
         "commands.\n\n");
}

void repl(void *list, listInterface *li) {
  int command;

  while (true) {
    putchar('>');
    fflush(stdout);

    command = getchar();

    if (command == 'q') {
      quitCommand();
      return;
    }

    bool valid = li->repl(command, list);
    if (!valid) {
      invalidCommand();
    }

    clearInputBuffer();
  }

  li->freeList(list);
}

int main() {
  printWelcome();
  startRepl();

  return 0;
}
