CC=g++
CFLAGS=-g

first: first.o second.o
	$(CC) $(CFLAGS) first.o second.o -o first

first.o: first.cpp
	$(CC) $(CFLAGS) -c first.cpp

second.o: second.cpp
	$(CC) $(CFLAGS) -c second.cpp

run: first
	./first

valgrind: first
	valgrind ./first

obj:
	mkdir -p obj

clean:
	rm -rf *.o first obj
