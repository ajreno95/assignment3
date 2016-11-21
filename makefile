CC=gcc
CFLAGS=-std=c99 -g
DEPS = command.h
OBJ = new.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myexec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
