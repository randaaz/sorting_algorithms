# 0x1B. C - Sorting algorithms & Big O

## Project Overview

This project involves implementing various sorting algorithms in the C programming language. The sorting algorithms to be implemented include Bubble Sort, Insertion Sort, Selection Sort, and Quick Sort. Additionally, the project focuses on understanding and analyzing the time complexity of these algorithms using Big O notation.

### Project Details

- **Project Due Date:** Dec 20, 2023 6:00 AM
- **Checker Release Date:** Dec 15, 2023 12:00 AM
- **Auto Review Deadline:** Project deadline

### Team Members

- **Team:** Rasha Saeed, Randa Saeed

## Project Learning Objectives

Upon completion of this project, you should be able to:

- Implement at least four different sorting algorithms.
- Understand and explain the concept of Big O notation.
- Evaluate the time complexity of an algorithm using Big O notation.
- Select the appropriate sorting algorithm for a given input.
- Understand the concept of stable sorting algorithms.

## Project Requirements

### General

- **Allowed Editors:** vi, vim, emacs
- **Compilation:** Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89
- All files should end with a new line.
- Your code should follow the Betty style, checked using betty-style.pl and betty-doc.pl.
- No global variables are allowed.
- No more than 5 functions per file.
- Unless specified otherwise, you are not allowed to use the standard library functions.
- Use the provided header file named `sort.h`, and include the prototypes of all your functions in it.
- All header files should be include guarded.

### tasks
3 mandatory tasks
9 advanced tasks

### Data Structure and Functions

For this project, you are provided with the following print_array and print_list functions:

```c
// Function to print an array of integers
void print_array(const int *array, size_t size);

// Function to print a doubly linked list of integers
void print_list(const listint_t *list);
