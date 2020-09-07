all: list.o main.o node.o 
	g++ -g obj/list.o obj/main.o obj/node.o -o all

list.o: src/list.cpp obj
	g++ -c src/list.cpp -o obj/list.o 

main.o: src/main.cpp obj
	g++ -c src/main.cpp -o obj/main.o

node.o: src/node.cpp obj
	g++ -c src/node.cpp -o obj/node.o

obj:  
	mkdir -p obj

#DPW: I think you forgot the space, did you test? (-25)
run:
	valgrind ./all
	
clean: 
	rm -rf *.o obj
	rm -f all

