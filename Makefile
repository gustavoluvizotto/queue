CC=gcc
CFLAGS=-c -Wall -g
TARGET=study

all: $(TARGET)

$(TARGET): main.o queue.o 
	$(CC) main.o queue.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) main.c

queue.o: src/queue.c
	$(CC) $(CFLAGS) src/queue.c

clean:
	rm *o $(TARGET)
