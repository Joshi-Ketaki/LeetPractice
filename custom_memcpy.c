#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

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

void *my_memset(void* str, int d, size_t n)
{
    
    unsigned char* ptr = (unsigned char*)str;
    int i = 0;
    while(i < n)
    {
        *ptr++ = d;
        i++;
    }
    return str;
}

void* my_memcpy(void* dest, const void* src, size_t size){
     unsigned char* myDest = (unsigned char*)dest;
     unsigned const char* mySrc = ( unsigned const char*)src;

     int i = 0;
     if(src != NULL && myDest != NULL)
     {
        while (i < size)
        {
            *(myDest++) = *(mySrc++);
            i++;
        }
     }
     return myDest;  
}

void* my_calloc(int n_items, size_t itemSize)
{
    int size = n_items * itemSize;
    struct block_meta* ptr = (struct block_meta*) my_malloc(size); 
    //memset(ptr, 0, size);
    my_memset(ptr, 0, size);
    return ptr;
}

void* my_realloc(void* reallocPtr, int size)
{
    struct block_meta* ptr = get_meta_block_ptr(reallocPtr);
    if(ptr == NULL)
    {
        //this is simply malloc
        struct block_meta* ptr = my_malloc(size);
        return ptr; 
    }

    if(size ==0 || ptr->size >= size)
    {
        //enough space. free and alloc as reqd. should be completed
        return ptr;
    }
    // if larger space is required
    void *newPtr = my_malloc(size);
    if(!newPtr)
        return NULL;
    my_memcpy(newPtr, ptr, size);
    free(ptr);
    return newPtr;
}



int main()
{
    int reqSize = 5;
    int* use = (int*)my_malloc(reqSize);
    *use = 5;
    printf("\n%d", *use);
    my_free(use);

    int* use2 = (int*)my_calloc(5, sizeof(int));
    *use2 = 10;
    printf("\n%d", *use2);
    my_free(use2);


    // try with malloc also
    int *use3 = (int*)my_realloc(use2, 10);
    printf("\n%d", *use3);
    my_free(use3);

    int *use4 = (int*)my_realloc(use2, 4);
    printf("\n%d", *use4);
    my_free(use4);

    int *use5 = (int*)my_realloc(use2, 0);
    printf("\n%d", *use5);
    my_free(use5);

    
    return 0;
}
