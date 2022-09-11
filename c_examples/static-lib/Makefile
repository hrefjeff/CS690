CC=gcc

all: my_prog library
	$(CC) -o my_prog my_prog.o -L . libcalc.a # Runs last

my_prog: my_prog.c
	$(CC) -c my_prog.c -o my_prog.o -I. # Runs 4th

library: adder_obj_file sub_obj_file
	ar -rv libcalc.a libsum.o libdiff.o  # Runs 3rd

adder_obj_file: mysum.c
	$(CC) -c mysum.c -o libsum.o # Runs 1st

sub_obj_file: mydiff.c
	$(CC) -c mydiff.c -o libdiff.o # Runs 2nd

clean:
	$(RM) my_prog *.o *~