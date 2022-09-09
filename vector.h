#ifndef VECTOR_H
#define VECTOR_H

#define push_back(this, push, type)                                         \
        this->len++;                                                        \
        this->arr = (type *) realloc(this->arr, this->len * sizeof(type));  \
        this->arr[this->len - 1] = push;                                    \

#define remove_at(this, index, type)                                        \
        for(int i=index;i<this->len;i++)this->val[i-1]=this->val[i];        \
        this->len--;                                                        \
        this->arr = (type *)realloc(this->arr, this->len * sizeof(type));   \

#define arr_cpy(this, arr, len, type)                                       \
        for(int i=index;i<len;i++)push_back(this,arr[i]type);               \

#define make_vec(name, type)                                                \
        type* name = malloc(sizeof(type));                                  \
        name->arr = malloc(0);                                              \
        name->len = 0;                                                      \

typedef struct
{
    int* arr;
    unsigned int len;
} intVector;


#endif