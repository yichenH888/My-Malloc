#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct block block_tag;

struct block{// only record free blocks in linked list
    size_t size;
    struct block* next;
    struct block* prev;
};

//First Fit malloc/free
void *ff_malloc(size_t size);
void ff_free(void *ptr);

//Best Fit malloc/free
void *bf_malloc(size_t size);
void bf_free(void *ptr);

unsigned long get_data_segment_size(); //in bytes
unsigned long get_data_segment_free_space_size(); //in byte

block_tag* block_new(size_t size);
void merge(block_tag* block);
block_tag * ff_findBlock(size_t size);
void split(block_tag * ptr, size_t size);
void printList(void);

block_tag* head = NULL;// head of linked list
block_tag* tail = NULL;// tail of linked list
block_tag* start = NULL; //start address

#endif