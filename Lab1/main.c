#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "mymalloc.h"

int main() {

	// Allocate some memory
	int* mem_ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (mem_ptr == MAP_FAILED){
		printf("mmap failed to allocate memory. lol\n");
		return 1;
	}



	return 0;
}
