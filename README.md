# Bit_set_C
Simple bit set implementation for educational purpose

The custom C library that provides the implementation of numerical set by bit-vectors.
Made with educational purpose.

bitset_dev.h and bitset.c - main implimintation. That bitset_dev.h is used for compilation by devs.

bitset.h - header for end users, without "heavy" doxygen comments.

## Implemetation
A Bit_set has 5 members:

* values - dynamic array of uint(32x or 64x). Each bit represents an element of set.
* amount - current amount of values of set
* max_amount - max amount of feasible values
* min - a min value of universal set(U)
* max - a max value of universal set(U).

You should provide only min and max values of U, and you will get
a set with U as [min;max].

What you can do:

* Create set
* Check is value in set
* Check is value in U of set
* Add value in set
* Delete value from set
* Output set (like { 1, 2, 3 }, {} and etc) 
* Complement set
* Destroy set values (deallocate dynamic array)

## How to compile/use
To use Bit_set just add `#include "bitset.h"` at the top of your source file

There are two possibilities for compile:

* You can just compile your source file with bitset.c like `gcc your_source.c bitset.c -o your_program`, but this may require using of flags inside of your source file.
* You can create a static library from bitset.c with needed flags and use it:
1. `gcc bitset.c -Wall -c -fopenmp`
2. `ar r libbitset.a bitset.o`
3. `gcc your_source.c -Wall -L. -lbitset -o your_program -fopenmp`

Warning! -fopenmp is optional flag, if you want to use multiply threads. If you don't want - just don't type it and don't use \_\_BITSET_OMP\_\_ flag.

---
TODO:

* Bit_set structure with static values array
* More operations? (Maybe, lots of them only with static version)
