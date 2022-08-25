#include <stdio.h>
#include <sys/mman.h>

int main(){
	int arr_size = 5;
	int* mem_ptr = mmap(
			NULL,
			arr_size*sizeof(int),
			PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS,
			0,
			0
			);

	if (mem_ptr == MAP_FAILED){
		printf("mmap failed to allocate memory\n");
		return(1);
	}

	for (int i=0; i<arr_size; i++) mem_ptr[i] = i;

	for (int i=0; i<arr_size; i++) printf("[%d]",mem_ptr[i]);

	printf("\n");


}
