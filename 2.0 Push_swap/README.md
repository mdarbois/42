The purpose of this project is sort data on a stack, with specific rules, using the lowest possible number of actions.

The push_swap program takes a set of int values, sorts the values using rules and writes commands that make the set sorted. 
To do this, you need think the algorithm and implement it.

Rules

We have 2 stacks named a and b. To start with:

a - contains a random number of either positive or negative numbers without any duplicates
b - is empty
The goal is to sort in ascending order numbers into stack a. To do this we have the following commands at your disposal:

sa - swap a swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements
sb - swap b swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
ss - swap a and swap b at the same time
pa - push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty
pb - push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty
ra - rotate a - shift up all elements of stack a by 1. The first element becomes the last one
rb - rotate b - shift up all elements of stack b by 1. The first element becomes the last one
rr - rotate a and rotate b at the same time
rra - reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one
rrb - reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one
rrr - reverse rotate a and reverse rotate b at the same time

Example of working push_swap:

Input parameters and output of the implemented programme:

$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
