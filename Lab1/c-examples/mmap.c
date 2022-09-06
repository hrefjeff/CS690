#include <stdio.h>
#include <sys/mman.h>

int main(){
	int arr_size = 5;
	int* mem_ptr = mmap(
			NULL, // specifies the starting address of the allocation (NULL means the kernel chooses the starting address)
			arr_size*sizeof(int), // specifies the length of allocation in bytes and should be > 0
			PROT_READ | PROT_WRITE, // prot = protection level, pages can be read & wrote to
			MAP_PRIVATE | MAP_ANONYMOUS, // flags for customization, private means owned by a single process, anon pages are not backed by file. mcalloc could use this flag to create a large memory allocation
			-1, // file descriptor, not needed when using MAP_ANON and is set to -1 here
			0 // offset
			);

	if (mem_ptr == MAP_FAILED){
		printf("mmap failed to allocate memory\n");
		return(1);
	}

	for (int i=0; i<arr_size; i++) mem_ptr[i] = i;

	for (int i=0; i<arr_size; i++) printf("[%d]",mem_ptr[i]);

	printf("\n");


}
