#include <stdio.h>
#include <sys/mman.h>
#include "mymalloc.h"

static node* freelist_head;

// Splitting - When allocation occurs, the allocator needs to find a free
//             chunk of memory that can satisfy the request and split it into two
//             The first chunk it will return to the caller
//             The second chunk will remain on the list
//             Request for 1byte: return addr of byte, and then update list

// Coallescing - When memory is freed, look at the addr you are returning as well as
//               nearby chunks of free space; if the newly freed space sits right next to one (or two)
//               existing free chunks, merge them into a single larger free chunk.
//               Update the list accordingly

node* getFreeListHead() {
  return freelist_head;
}

void setFreeListHead(node* n){
  freelist_head = n;
}

int initializeList() {
  // Allocate 4KB of memory
	node* HEAD = mmap(NULL, LIST_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	HEAD->size = LIST_SIZE - sizeof(node); // embedding the list within the allocated space
	HEAD->next = NULL;

	/* Freelist currently looks like this:
		hr->  ______________________
			    | size: 4 byte int    |
          | node: 12 byte struct|
 		ptr-> -----------------------
			    | size: 1008          |
			    |                     |
			    |                     |
			    |                     |
			    |_____________________|
	*/

	// Check to see if it allocated
	if (HEAD == MAP_FAILED){
		printf("mmap failed to allocate memory. lol\n");
    return 1;
	} else {
    freelist_head = HEAD;
    return 0;
  }
}

node* firstFitSearch(node *n, size_t memsize) {
  while (n != NULL) {
    if (n->size > memsize) return n;
    n = n->next;
  }
  return NULL;
}

void* myMalloc(size_t memsize) {
    // find chunk of mem (first fit strat)
    node* head = getFreeListHead();
    node* free_section = firstFitSearch(head, memsize);
    // if found
    if (free_section != NULL) {
      // split it
      // first chunk: put header info on 
      // Allocate mem for new node
      node *new_node = mmap(&free_section, memsize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

      // Assign vals
      new_node->size= memsize;
      new_node->next = NULL;

      // Begin traversal of list and find end
      node *temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      
      // Assign the last node's next to newly created node
      temp->next = new_node;

      // second chunk: remain on the list
      head->size = head->size - memsize;

      return new_node;
      
    } else {
      printf("Nah. That request is too big.\n");
      return NULL;
    }
}

void myFree(void *ptr) {
    header_region *hptr = (void *)ptr - sizeof(struct header_region); // this points to size
    unsigned int size_of_chunk = hptr->size;
    unsigned int addr_of_chunk = hptr->addr;
    // update list with this info
}

void printList(node* n){
  int i = 0;
  while (n != NULL) {
    printf("Node %d has size %d \n", i, n->size);
    n = n->next;
    i++;
  }
  printf("\n");
}