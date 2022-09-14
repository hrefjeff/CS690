#include <stdio.h>
#include "mymalloc.h"

// Splitting - When allocation occurs, the allocator needs to find a free
//             chunk of memory that can satisfy the request and split it into two
//             The first chunk it will return to the caller
//             The second chunk will remain on the list
//             Request for 1byte: return addr of byte, and then update list

// Coallescing - When memory is freed, look at the addr you are returning as well as
//               nearby chunks of free space; if the newly freed space sits right next to one (or two)
//               existing free chunks, merge them into a single larger free chunk.
//               Update the list accordingly


// Begin Utility Functions

freelist_node firstFitSearch(freelist_node *n, size_t memsize) {
  while (n != NULL) {
    if (n->size > memsize) return n;
    n = n->next;
  }
  return NULL;
}

int* mymalloc(freelist_node *n, size_t memsize) {
    // find chunk of mem (first fit strat)
    freelist_node free_section = firstFitSearch(n, memsize);
    // if found
    if (free_section != NULL) {
      // TODO: Find out how to split
      // split it
      // first chunk: put header info on 
      // second chunk: remain on the list
    } else {
      return NULL;
    }
}

void myfree(void *ptr) {
    struct header_region *hptr = (void *)ptr - sizeof(struct header_region); // this points to size
    int size_of_chunk = hptr->size;
    // update list with this info
}