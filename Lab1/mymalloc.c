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

void searchList(freelist_node *n) {
  while (n != NULL) {
    printf("%d\n", n->size);
    n = n->next;
  }
}

int* mymalloc(freelist_node *n, size_t memsize){
    // find chunk of mem
    searchList(n);
    // split it
    // first chunk: put header info on 
    // second chunk: remain on the list
}

void myfree(void *ptr){
    struct header_region *hptr = (void *)ptr - sizeof(struct header_region); // this points to size
    int size_of_chunk = hptr->size;
    // update list with this info
}