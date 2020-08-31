all: first second third

run: first second third
	./first > first.data
	./second > second.data
	./third > third.data

first: src/first.cpp
	g++ src/first.cpp -o first

second: src/second.cpp
	g++ src/second.cpp -o second

third: src/third.cpp
	g++ src/third.cpp -o third

plot: timings.plot first.data second.data third.data
	gnuplot < timings.plot
	evince output.ps

clean:
	rm first second third *.data output.ps
