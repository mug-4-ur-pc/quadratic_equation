CC=gcc
CFLAGS=-Wall -Wextra
LD=gcc
LDFLAGS=-lm
OUTPUT= square.out


all: compile

.PHONY: run
run: compile
	./$(OUTPUT)

.PHONY: test
test: test.out
	./test.out

test.out: square.o test.o main_test.o
	$(LD) $(LDFLAGS) square.o test.o main_test.o -o test.out

.PHONY: compile
compile: $(OUTPUT)

$(OUTPUT): main.o square.o
	$(LD) $(LDFLAGS) main.o square.o -o $(OUTPUT)

main.o: main.c square.h
	$(CC) -c $(CFLAGS) main.c

square.o: square.c square.h
	$(CC) -c $(CFLAGS) square.c

test.o: test.c test.h square.h
	$(CC) -c $(CFLAGS) test.c

main_test.o: main.c test.h
	$(CC) -c -DTEST $(CFLAGS) main.c -o main_test.o

.PHONY: clean
clean:
	rm -f *.o *.out
