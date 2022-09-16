#include <stdlib.h>
#include "mymalloc.h"

int main() {

	int status = initializeList();
	if (status == 1) return 1; // In case initial memory mapping failed

	node* thehead = getFreelistHead();

	printList(thehead);
	int* first_alloc = myMalloc(100);
	
	return 0;
}
