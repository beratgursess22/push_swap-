# push_swap-

The Push_Swap project aims to teach you the basics of sorting algorithms and how to efficiently manage data in a constrained environment
The project focuses on implementing a sorting algorithm using only a stack-based approach and optimizing the number of operations used to sort a list of numbers.

1-In this project, you are required to:

a-Sort a stack of integers.
b-Use two stacks (stack A and stack B).
c-Perform sorting by using only a limited set of operations.
d-Optimize your solution to minimize the number of operations.

2-Push_Swap Operations

You are allowed to perform the following operations to manipulate the two stacks:

sa (swap a): Swap the top two elements of stack A.
sb (swap b): Swap the top two elements of stack B.
ss (swap both): Perform sa and sb simultaneously.
pa (push a): Pop the top element from stack B and push it to stack A.
pb (push b): Pop the top element from stack A and push it to stack B.
ra (rotate a): Shift all elements of stack A up by one position. The first element becomes the last.
rb (rotate b): Shift all elements of stack B up by one position. The first element becomes the last.
rr (rotate both): Perform ra and rb simultaneously.
rra (reverse rotate a): Shift all elements of stack A down by one position. The last element becomes the first.
rrb (reverse rotate b): Shift all elements of stack B down by one position. The last element becomes the first.
rrr (reverse rotate both): Perform rra and rrb simultaneously.

3-Push_Swap Project Steps

A-Input Parsing

The first step is to parse the input, which could be a list of integers passed through the command line.
You need to check for valid inputs, such as duplicate numbers, negative values, and correct integer ranges.

B-Sorting the Stack

You must sort the stack using only the allowed operations.
One of the challenges is to minimize the number of operations, meaning you must implement an efficient sorting algorithm.

C-Choosing an Efficient Algorithm

The project encourages you to implement efficient sorting algorithms for small and large sets of data.
The most basic algorithm that you can use is Bubble Sort, but this is inefficient.

D-Optimization

You need to optimize your algorithm to use the fewest number of operations possible.
The project challenges you to come up with strategies that minimize operations like swaps, pushes, and rotations.

