#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include "macros.h"
#include <stdio.h>

// Add an element to the end of the vector
// this is a pointer to the vector that is being modified
// push is the value that is being added to the vector
// type is the type of the push value and vector
#define push_back(this, push)                                                                   \
        this->len++;                                                                            \
        {typeof(push) * _r = realloc(this->arr, this->len * sizeof(typeof(push)));            \
        if (_r) { this->arr = _r; } else { printf("FATAL ALLOCATION ERROR"); exit(2); }}        \
        this->arr[this->len - 1] = push;                                                        \

// Remove an element from a given index in the vector
// this is a pointer to the vector that is being modified
// index is the index of the value being removed
// type is the type of the vector
// the function is not safe if you use values outside the bounds of the array
#define remove_at(this, index)                                                                            \
        for(int i=index+1;i<this->len;i++){this->arr[i-1]=this->arr[i]; }                                 \
        this->len--;                                                                                      \
        {typeof(this->arr[0]) * _r = realloc(this->arr, this->len * sizeof(typeof(this->arr[0])));        \
        if (_r) { this->arr = _r; } else { printf("FATAL ALLOCATION ERROR"); exit(2); }}                  \

// Copies an array into the given vector
// this is a pointer to the relevant vector
// arr is a pointer to the array being copied
// len is the length of the array
// type is the type of the vector and array
#define arr_cpy(this, arr, len)                           \
        loop(i, len){push_back(this,arr[i]);}             \

// Initialises a vector
// Name is the name of the vector being made
// type is the type of the vector being made
// not really useful with structs that have extra values beyond arr and len
#define make_vec(name, type)                                                \
        type* name = malloc(sizeof(type));                                  \
        name->arr = malloc(0);                                              \
        name->len = 0;                                                      \

// Frees the memory used in a vector
// DO NOT use this with custom vectors
// It only frees the memory used in arr and the vector itself, so if a struct allocates any more memory it will be left unallocated with no way to free it
#define destroy_vec(this)                                                   \
        free(this->arr);                                                    \
        free(this);                                                         \

typedef struct
{
    // A pointer to the type that this vector will hold
    // This pointer holding the values must be named arr
    void* arr;   
    // The length of the vector (can be any number type)
    // The value holding the length must be named len
    unsigned int len;
    // Functions even if you have more variables in the struct
    char someChar;

} templateVector;


#endif