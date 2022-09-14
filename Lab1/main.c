#include <stdlib.h>
#include <sys/mman.h>

#include "mymalloc.h"

int main() {

	// Allocate 4KB of memory
	freelist_node *head = mmap(NULL, LIST_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	head->size = LIST_SIZE - sizeof(freelist_node); // embedding the list within the allocated space
	head->next = NULL;

	/* Freelist currently looks like this:
		hr->  ______________________
       		  |                    |
			  | size: 4 byte int   |
 		ptr-> ----------------------
			  | size: 4092         |
			  |                    |
			  |                    |
			  |                    |
			  |____________________|
	*/

	// Check to see if it allocated
	if (head == MAP_FAILED){
		printf("mmap failed to allocate memory. lol\n");
		return 1;
	}

	int* first_alloc = mymalloc(head, 100);

	

	return 0;
}
