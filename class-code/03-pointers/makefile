CC=g++

# This is a comment!
# IE: I used <url> to help me.
main: main.o 
	$(CC) main.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

run: first
	./first

obj:
	mkdir -p obj

clean:
	rm -rf *.o first obj
