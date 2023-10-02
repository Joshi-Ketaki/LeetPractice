#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<assert.h>


struct block_meta {
    int size;
    bool isFree;
    struct block_meta *next;
};
#define META_SIZE sizeof(struct block_meta)
struct block_meta* head = NULL;
struct block_meta* last = NULL;

struct block_meta* is_free_space(int size)
{
    struct block_meta* ptr = head;
    while(ptr && !(ptr->isFree && ptr->size >= size))
    {
        last = ptr;
        ptr = ptr->next;
    }
    return ptr;
}

struct block_meta* request_space(int size)
{
    struct block_meta* curr_base = (struct block_meta*) sbrk(0);
    // we are storing meta info also
    struct block_meta* request_base = (struct block_meta*) sbrk(META_SIZE + size);
    if(request_base == (void*) - 1)
        return NULL;
    /*if(request_base == (void*)curr_base){
        printf("\n Not thread safe");
        exit(0);
    }*/
    request_base->isFree = false;
    request_base->size = size;
    request_base->next = NULL;

    return request_base;
}

struct block_meta* get_meta_block_ptr(void* ptr)
{
    return (struct block_meta*)ptr;
}

void my_free(void* ptr)
{
    if(!ptr)
        return;
    struct block_meta* toFreePtr = get_meta_block_ptr(ptr); 
    //if(toFreePtr == NULL)
    //    printf("null ptr");
    //check this
    //assert(toFreePtr->isFree == true);
    toFreePtr->isFree = true;
    //toFreePtr->next = NULL;
}

void* my_malloc(int size)
{
    struct block_meta* ptr;
    if (size == 0)
    {
        return NULL;
    }
    if(!head)
    {
        head = request_space(size);
        last = head;
        return head;
    }
    else
    {
        ptr = is_free_space(size);
        if(!ptr){
           last->next = request_space(size); 
           last = last->next;
        }
        else
        {
            ptr->isFree = false;
            ptr->size = size;
            last->next = ptr;
            last = last->next;
        }
    }
    return last; //+ 1; // not caste to void*
}

int main()
{
    int reqSize = 100;
    int* use = (int*)my_malloc(reqSize);
    *use = 5;
    printf("%d", *use);
    my_free(use);
    return 0;
}
