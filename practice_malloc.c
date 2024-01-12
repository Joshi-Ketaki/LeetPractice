/**
(C) Ketaki Joshi, November, 2023
This code has been developed as part of the personal practice sessions for Ketaki Joshi. These are quickly implemented solutions.
So, they will not have asserts/checks or comments at all points.
If you intend to use this code, you are responsible for your own bounds checking, and other checks to be inserted or performed.

Resources: 
Here is a good starting tutorial if you want to start from scratch or want to refresh your concepts: 
1. https://manybutfinite.com/post/anatomy-of-a-program-in-memory/
I refreshed concepts through this tutorial, so some parts of the implementation might look similar. The difference is 
that I have also added mmap versions in addition to sbrk implementation. You can skip either one.
This tutorial can take you to multiple sources as you read through it. 
Try to cater your study by prioritizing what you need to brush up on. If you do not structure it, you might get lost. 

**/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <sys/mman.h>
#include <errno.h>

typedef struct block{
    size_t size;
    struct block* prev;
    struct block* next;
} block_t;

#define PAGESIZE (4 * 1024)
#define MAX_ALLOC 1* sysconf(_SC_PAGESIZE)

#define MIN_DEALLOC 1* sysconf(_SC_PAGESIZE)

#define BLOCK_MEM(ptr) (void*)((unsigned long)ptr + sizeof(block_t))
#define BLOCK_HEADER(ptr) (void*)((unsigned long)ptr - sizeof(block_t))

block_t* head = NULL;

void freeListRem(block_t *ptr)
{
    printf("\n in freelist");
    //if(!head) return;
    //block_t *tmp;
    if(!ptr->prev && ptr->next){
	// ptr is head. Remove ptr.
	head = ptr->next;
	return;
    }
    else if(!ptr->prev && !ptr->next) {
	head = NULL;
	return;
    }
    if(ptr->next){
	ptr->next->prev = ptr->prev;
    }
    if(ptr->prev){
	ptr->prev->next = ptr->next;
    }
    //ptr->prev = NULL;
    //ptr->next = NULL;
    //}     
    printf("\n leaving freeList");
}


void freeListAdd(block_t * ptr)
{
   if(!head){
	head = ptr;
	return;
   } 
   else if((unsigned long)head >  (unsigned long) ptr)
   {
	head->prev = ptr;
	ptr->next = head;
	head = ptr;;
   }
   block_t *curr = head, *tmp;
   while(curr->next && (unsigned long)curr->next < (unsigned long)ptr)
   {
	curr = curr->next;
   }
   ptr->next = curr->next;
   curr->next->prev = ptr;
   curr->next = ptr;
   ptr->prev = curr;
}


block_t* splitBlk(block_t* ptr, size_t size){
    block_t* newPtr;

    newPtr->size = ptr->size - (size+sizeof(block_t));
    ptr->size = size+sizeof(block_t);
    newPtr->next = NULL;
    newPtr->prev = NULL;
    return newPtr;
}


void* my_malloc(size_t size)
{
    if(size == 0) return sbrk(0);
    block_t *ptr, *newPtr;

    ptr = head;
    while(ptr){
	printf("\n in while");
	if(ptr->size >= size+sizeof(block_t)){
	  printf("\n in if");
	  freeListRem(ptr);
	  //return ptr;
	  block_t * blk = BLOCK_MEM(ptr);
	  if(ptr->size == size+sizeof(block_t)){
	    return blk;
	  }
	  else{
	    printf("\n in else");
	    newPtr = splitBlk(ptr, size);
	    freeListAdd(newPtr);
	    return blk;
	  }
	}
	ptr= ptr->next;
    }

    // Ask OS for more memory and store remaining in freeList
    int alloc_size = ((size + sizeof(block_t)) >= MAX_ALLOC) ? (size + sizeof(block_t)) 
	    : MAX_ALLOC;
    //ptr = sbrk(alloc_size);
    ptr = mmap(NULL, alloc_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
              -1, 0);
    if (ptr == MAP_FAILED) {
    //if(!ptr){
	printf("\n alloc failed");
	exit(0);
    }
    // for mmap, return this i.e. ptr returned by mmap for mumap to work correctly
    // mummap requires pointer returned by mmap
    //return ptr;
    ptr->size = (size + sizeof(block_t));
    ptr->next = NULL;
    ptr->prev = NULL;
    if((size+sizeof(block_t)) < alloc_size )
    {
        printf("\n splitting");
	newPtr = splitBlk(ptr, size);
	freeListAdd(newPtr);
    }
    // for mmap, return this i.e. ptr returned by mmap for mumap to work correctly
    // mummap requires pointer returned by mmap
    return ptr;
    block_t * blk = BLOCK_MEM(ptr);
    return blk;
}

void scanAndMerge()
{
   block_t* curr=head, *nxt;
   printf("\n in scan and merge");
   while(curr->next){
	if((unsigned long) curr + curr->size + sizeof(block_t) == 
			(unsigned long) curr->next)
	{
	    curr->size = curr->size + curr->next->size + sizeof(block_t);
	    //block_t* fnext = curr->next->next;
	    if(curr->next) {
		curr->next->prev = curr;
	    }
	    else{
		break;
	    }
	}
	curr = curr->next;
   }
   printf("\n reached here");
   void* pb = sbrk(0);
   if((unsigned long) pb == 0) 
   {
	printf("\n error in retrieving program break");
	return;
   }
   if(((unsigned long) curr + curr->size + sizeof(block_t) == (unsigned long)pb) &&
	(curr->size >= MIN_DEALLOC)    )
   {
	// its big enough that we can release to OS
	freeListRem(curr);
	// adjust program break;
	if(brk(curr) != 0)
	{
	    printf("\n error in freeing last block");
	    return;
	}
   }

}

void my_free(void* ptr)
{
    //freeListAdd(BLOCK_HEADER(ptr));
    freeListAdd(ptr);
    scanAndMerge();
}


void* my_calloc(size_t size)
{
    block_t* ptr = (block_t*) my_malloc(size);
    //memset((void*)ptr, 1, 5*1024);
    char* charPtr = (char*) ptr;
    for(int i = 0; i < size; i++){
	*(charPtr+i) = 0;
    }
    
    return ptr;
}

void* my_realloc(void *ptr, size_t size)
{
    block_t* newPtr;
    block_t* oPtr = (block_t*)ptr;
    // no change
    if(size == 0 || size < oPtr->size){
	return ptr;
    }
    newPtr =  my_malloc(size);
    //memcpy(newPtr, oPtr, oPtr->size);
    char* newP = (char*) newPtr;
    char* oP = (char*) oPtr;
    for(int i=0; i < oPtr->size; i++){
	newP[i] = oP[i];
    }
    my_free(oPtr);
    return newPtr;
}

void main()
{
    /*int *p = (int*) my_malloc(1*1024);
    *p = 50;
    printf("\n Malloced value:%d", *p);
    free(p);*/

    double  *p = (double*) my_malloc(5*1024);
    *p = 100;
    //double *q = (double*) my_realloc(p, 6*1024);
    //*q = 400;
    printf("\n 2. Malloced value:%lf", *p); 
    //my_free(q);
    if(munmap((void*)p, 5*1024) == -1){
	printf("\n error in munmap: %d", errno);
	exit(0);
    }


    //int  *qi = (int*) my_malloc(5*1024);
    //*qi = 200;
    //printf("\n 3. Malloced value:%d", *qi);
    //my_free(qi);

}
