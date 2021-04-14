/*
  bitset.h

    Made by DanArmor
    https://github.com/DanArmor

  The custom C library with implementation of numerical set by bit-vectors

*/

/**
 * @file
 * @brief The header of custom C library that provides the implementation of numerical set by bit-vectors
 * @author DanArmor \n https://github.com/DanArmor
 * 
 */

#pragma once
#ifndef __BITSET_DEFINED__ // Include guard for 3rd party interop
#define __BITSET_DEFINED__

#include <stdint.h>
#include <inttypes.h>

#ifdef __BITSET_LIB__ //For compilation of library (bitset.c)
  #include <stdlib.h>
  #include <stdio.h>

  #ifdef __BITSET_OMP__
    #include <omp.h>
  #endif

  #define __BITSET_ERROR_CODE__ 201 //TODO more error codes ?
  //Meaning: Something went wrong 

  #define putserr(error) fputs(error, stderr)
  #define printerr_value(v) fprintf(stderr, "Error value : %lld" , v)
  #define r_uint register uint

#endif //__BITSET_LIB__

#if (defined(_WIN64) || defined(__BITSET_64__)) && !defined(__BITSET_32__)
  #define PARAMETER_ERR "%"PRIuFAST64
  typedef uint_fast64_t uint;
#else
  #define PARAMETER_ERR "%"PRIuFAST32
  typedef uint_fast32_t uint;
#endif

/**
 * @brief Sets the max number of used threads as a half of max \n 
 * Executes before main() \n 
 * if <b>\__BITSET_OMP__</b> was turned off - it will do nothing 
 * 
 */
extern void __BITSET_SET_THREADS_NUMBER__(void) __attribute__ ((constructor));

//We take that values from implementation (bitset.c)
extern const uint SIZE_UINT_BYTES;
extern const uint SIZE_UINT_BITS;
extern const uint MASK_LAST_LEFT;

/**
 * @struct Bit_set
 * @brief This structure is an implementation of numerical set by bit-vectors
 * @var Bit_set::values
 * This is a dynamic array of uint(as bit-vectors).
 * @var Bit_set::amount
 * Amount of current values of set
 * @var Bit_set::max_amount
 * Max amount of feasible values of set
 * @var Bit_set::min
 * This is a min value of universal set.
 * @var Bit_set::max
 * This is a max value of universal set.
 */
typedef struct Bit_set{
  uint *values;
  unsigned long long amount;
  unsigned long long max_amount;
  long long min;
  long long max;
} Bit_set;

//Returns a bitset, that has universal set as [min;max]
/**
 * @brief Returns a bitset, that has universal set as [min;max]
 * @details <b>Be careful</b>. It creates a dynamic array
 * @param min
 * @param max 
 * @return Bit_set 
 */
Bit_set create_set(long long min, long long max);

//Adds a value into a set
/**
 * @brief Adds a value into a set
 * 
 * @param set 
 * @param value 
 */
void add_set(Bit_set *set, long long value);

//Retuns 1, if value is in set. Else = 0
/**
 * @brief Retuns 1, if value is in set. Else = 0
 * 
 * @param set 
 * @param value 
 * @return int 
 */
int is_in_set(Bit_set *set, long long value);

//Outputs a set into stdout.
/**
 * @brief Outputs a set into stdout.
 * 
 * @param set 
 */
void output_set(Bit_set *set);

/**
 * @brief Get the amount of values of set
 * 
 * @param set 
 * @return unsigned long long 
 */

//Performs a complement operation on a set
/**
 * @brief Performs a complement operation on a set
 * 
 * @param set 
 */
void complement_set(Bit_set *set);

//Deletes a value from a set
/**
 * @brief Deletes a value from a set
 * 
 * @param set 
 * @param value 
 */
void delete_from_set(Bit_set *set, long long value);

//Deallocates the space previously allocated for values of set
/**
 * @brief Deallocates the space previously allocated for values of set
 * 
 * @param set 
 */
void destroy_set_values(Bit_set *set);



#endif //__BITSET_DEFINED__
