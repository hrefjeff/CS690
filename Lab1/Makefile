# Compiler: gcc for the C program
CC=gcc

# Compiler flags:
# -I. for searching current directory
CFLAGS = -I.

# Build target
TARGET = labprogram

DEPS = mymalloc.h
OBJ = something.o anotherthing.o

%.o: 

lab1make: something.o anotherthing.o
	$(CC) $(CFLAGS) -o $(TARGET) main.c 

clean:
	$(RM) $(TARGET)
