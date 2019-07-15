CC := gcc
CFLAGS :=-std=c11 -Wall -Wextra -g
EXEC := rm0 cat0 ls0 stat0 test

all: $(EXEC)

ls0: fmanagment.o

cat0: fmanagment.o

test: testing.o

run-test: $(EXEC)
	./test

clean:
	rm -f $(EXEC) *.o