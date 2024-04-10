##
<h1 align="center"> <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-push_swap-bonus.png" </h1>
  
## Description
Push Swap is a sorting algorithm project in C. It involves sorting a stack of integers using a limited set of operations. The goal is to arrange the numbers in ascending order using two stacks and a set of rules for manipulating the elements.

## Project Components Table
The following table describes the various components and files included in the Push Swap project:

| File/Header File/Folder     | Description                                                                                         |
|----------------------|-----------------------------------------------------------------------------------------------------|
| `push_swap.c`        | The main file containing the implementation of the Push Swap algorithm.                            |
| `parsing_args.c`     | Handles argument parsing for the Push Swap project.    |
| `end_sort.c`         | Contains functions to handle the end of sorting process in the Push |
| `algorithm`          | Implements the sorting algorithm for the Push Swap project. |
| `exec`               | Executes the sorting instructions on the stack. |
| `instructions`       | Contains the implementation of stack manipulation |
| `libft`              | A directory containing the Libft library, used for some auxiliary functions.                        |
| `Makefile`           | The Makefile script for automating project compilation.                                            |

## Installation and Compilation
1. Clone this repository into your project:
```bash
git clone https://github.com/cypri1-dev/42_push_swap.git
cd 42_push_swap
```

## How to use ?
```bash
./push_swap [random_numbers]
```

## Features
The Push Swap project offers the following features:

- **Sorting Algorithms**: Implements efficient sorting algorithms to order a stack of integers in ascending order.

- **Instruction Management**: Provides a variety of stack manipulation instructions such as "push", "swap", "rotate", and "reverse rotate" to sort the stack according to specified rules.

- **Sorting Verification**: Verifies if the stack is correctly sorted after executing sorting operations to ensure the accuracy of the algorithm.

- **Performance Optimization**: Searches for the most efficient instruction sequences to minimize the total number of operations required to sort the stack.

- **Easy Customization**: Offers the ability to customize and extend functionalities by adding new sorting algorithms or modifying stack manipulation instructions.

- **Norminette Compatibility**: Adheres to coding and style standards defined by the norminette to ensure code consistency and readability.
