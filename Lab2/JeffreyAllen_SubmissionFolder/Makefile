CSAPP_INC = ./include
CSAPP_SRC = ./src

CFLAGS = -Og -Wall -I $(CSAPP_INC) -I .
LDLIBS = -lpthread -lm

# NOTE: we expect sharing.c to generate warnings
PROGS =	echoclient\
	echoservers\

all: $(CSAPP_SRC)/csapp.o $(PROGS)
$(PROGS): $(CSAPP_SRC)/csapp.o 
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

echoservers: echoservers.o echo.o

clean:
	rm -f $(PROGS) *.o *~ inlcude/*.o src/*.o
