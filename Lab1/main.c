#include <stdlib.h>
#include "mymalloc.h"

int main() {

	int status = initializeList();
	if (status == 1) return 1; // In case initial memory mapping failed

	node* thehead = getFreeListHead();

	printList(thehead);
	int* first_alloc = myMalloc(100);
	printList(thehead);
	int* second_alloc = myMalloc(50);
	printList(thehead);
	int* third_alloc = myMalloc(10000);
	printList(thehead);
	
	return 0;
}
