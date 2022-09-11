# Compiler: gcc for the C program
CC=gcc

all: main allocator_library
	$(CC) -o main main.o -L . libmalloc.a

main: main.c
	gcc -c main.c -o main.o

allocator_library: malloc.o
	ar -rc libmalloc.a mymalloc.o

malloc.o: mymalloc.c
	gcc -c mymalloc.c -o mymalloc.o

clean:
	$(RM) main *.o *~ *.a