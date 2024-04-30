# Push Swap

The "Push Swap" project is a coding challenge designed to sort data on a stack with a limited set of operations and using two stacks, named `a` and `b`. The objective is to sort the numbers in stack `a` in ascending order using the smallest number of operations.

## Warning for 42 Students

This repository is intended as a reference and educational tool. **42 students are strongly advised not to copy this code without fully understanding its functionality.** Plagiarism in any form is against 42's principles and could lead to serious academic consequences. Use this repository responsibly to learn and better understand how to implement similar functionalities on your own.

## Rules

- **Stack Initialization**: Initially, stack `a` contains a random set of negative and/or positive integers without any duplicates, and stack `b` is empty.
- **Goal**: Sort the integers in stack `a` in ascending order.

### Operations

- `sa` (swap a): Swap the top two elements of stack `a`.
- `sb` (swap b): Swap the top two elements of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa` (push a): Move the top element of stack `b` to stack `a`.
- `pb` (push b): Move the top element of stack `a` to stack `b`.
- `ra` (rotate a): Rotate stack `a` upwards.
- `rb` (rotate b): Rotate stack `b` upwards.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Rotate stack `a` downwards.
- `rrb` (reverse rotate b): Rotate stack `b` downwards.
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Compilation

```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make
