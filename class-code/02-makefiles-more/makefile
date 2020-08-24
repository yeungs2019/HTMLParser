CC=g++

# This is a comment!
# IE: I used <url> to help me.
first: first.o second.o
	$(CC) first.o second.o -o first

first.o: first.cpp
	$(CC) -c first.cpp

second.o: second.cpp
	$(CC) -c second.cpp

run: first
	./first

obj:
	mkdir -p obj

clean:
	rm -rf *.o first obj
