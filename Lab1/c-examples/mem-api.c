#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void someFunc();
void someOtherFunc();
void mallocPrintSize();
void forgetToAllocate();

int main()
{

	someFunc();
	someOtherFunc();
	mallocPrintSize();
	forgetToAllocate();

	unsigned int x = 5;
	printf("Size of unsigned int : %ld\n", sizeof(x));

	return 0;
}

void someFunc(){
	int x = 5; // declare int on the stack
}

void someOtherFunc(){
	int* x = (int *) malloc(sizeof(int));
	// malloc(size_t size) - where size_t is # of bytes needed
	// malloc is included within the stdlib.h library
	// You pass it a size asking for some room on the heap
	// it returns back a pointer to the newly-allocated heap space, or NULL if it fails
	// (NULL is just a macro for the value zero)

	double *d = (double *) malloc(sizeof(double));

	// Last note: malloc has a return type of void. This is just a way that C passes
	// back an address and lets the programmer decide what to do with it
	// int* x = (int *) malloc(sizeof(int)); is comparable to
	// int* x = malloc(sizeof(int));
	// they both work, but the first one says "yea, i know what im doing"
	
	free(x);
	free(d);
}

void mallocPrintSize(){
	int *x = (int *) malloc(10 * sizeof(int));
	// printf("%d\n", sizeof(x)); Printing with %d on long unsigned int causes a warning
	printf("%lu\n", sizeof(x)); // lu is for long unsigned ints
				    // This prints 8 (64-bit machines) because I'm asking how
				    // big a pointer is. Not how much space we dynamically allocated
	int y[10];
	printf("%lu\n", sizeof(y));

	free(x);

}

void forgetToAllocate(){
	char *src = "hello";
	//char *dst; // forgot to allocate memory. segfault and die
	//char *dst = (char *) malloc(2); // not enough memory. will run sometimes... BUT ITS NOT CORRECT
	char *dst = (char *) malloc(strlen(src) + 1); // just right. no segfault
	strcpy(dst, src);

	free(dst);
}
