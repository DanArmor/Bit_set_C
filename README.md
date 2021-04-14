# Bit_set_C
Simple bit set implementation for educational purpose

The custom C library that provides the implementation of numerical set by bit-vectors.
Made with educational purpose.

bitset.h and bitset.c - main implimintation

bitset_user.h - header for end users, without "heavy" doxygen comments.

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
---
TODO:

* Bit_set structure with static values array
* More operations? (Maybe, lots of them only with static version)
