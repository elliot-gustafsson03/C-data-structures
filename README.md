# C Data Structures

This is a simple REPL program in the C programming language, written as an excercise to learn the basics of pointers and memory allocation.

## About

This program uses a CLI (Command Line Interface) to create and modify different types of data structures. Currently the following are implemented:

-   Array list
    > An array is stored as a sequence of blocks in the memory, allowing for quick retrieval of the value at a certain position. To improve memory efficiency, the capacity of the list increases as needed.
-   Linked list
    > A linked list works like a chain, connecting each list element to the next one. This means that getting the value at a certain position is quite unefficient, since we must go through the whole list until we get to the desired position.

## Running the program

To run this program, you will need a C compiler, for example [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/)

To compile every file in the repository, write:

```bash
$ clang --output <file_name> *.c lists/*.c
```

This will create an executable with the given file name. To run it, simply write:

```bash
$ ./<file_name>
```
