# Push_Swap
A constrained sorting algorithm: Recursively solved

Goal: Sort N numbers on a stack, ascending from top (lowest) to bottom (highest), with least amount of operations

Restrictions/rules:
- There are 2 stacks available, numbers must always be in either one of these.
- Moving numbers can only be done using subject-defined operations:
1. Swap: Swap top 2 numbers of a stack
2. Rotate: Rotate all numbers on a stack by 1
3. Reverse Rotate: Rotate in reverse order
4. Push: Move a number to the other stack

My approach:

The 2 stacks (a and b) will be divided in sub-arrays.

1. At first the stacks look like this:

A           B
[UNSORTED]  [EMPTY]

Then we start by grouping numbers:
[HIGH]  = highest 1/3
[MED]   = medium 1/3
[LOW]   = lowest 1/3

Placed on these specific places:

        [MED]
[HIGH]  [LOW]

Let's start with an example: 18 numbers.

[0-17]   [EMPTY]

[12-17]   [6-11]
          [0-5]

[15-17]   [13-14]
          [6-11]
          [0-5]
          [12]

[17]      [16]
          [13-14]
          [6-11]
          [0-5]
          [12]
          [15]
