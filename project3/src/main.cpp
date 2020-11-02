#include <stdio.h>
#include <iostream>
#include <time.h>
#include "splay.hpp"

int main(int argc, char *argv[]){
    int sum;
    SplayTree<int> bt;
    splayNode<int>* root = NULL;
    //preOrder(root);
    /* clock_t is the data type for stroing timing information.
     * We must make two variables, one for the start and the other to capture
     * the difference.
     */
    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    //We want to run our algorithm over varying sizes.
    for(int i = 1; i < 100000; i += 100){
	// capture the start clock
	start = clock();

	// This is where your algorithm should be called.
	// Keep in mind that i is the SIZE of the input -- you may have to change it!
	for (int j = 0; j < i; j++){
	    root = bt.deleteKey(root, i);
	}

	// Capture the clock and subtract the start to get the total time elapsed.
	diff = clock() - start;

	// Convert clock_t into seconds as a floating point number.
	timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

	//Print out the first the size (i) and then the elapsed time.
	std::cout << i << " " << timeAmount << "\n";

	// We flush to ensure the timings is printed out
	std::cout << std::flush;
    }
    return 0;
}
