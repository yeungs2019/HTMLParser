#include <iostream>
#include <time.h>

bool is_prime(const int num) {
    if (num == 2) { return true; }
    if (num < 2) { return false; }

    for (int i = 3; i < num; i++) {
        if (num % i == 0) { return false; }
    }

    return true;
}

int how_many_primes(const int N) {
    int sum = 0;

    for (int i = 2; i < N; i++) {
        if (is_prime(i)) { sum++; }
    }

    return sum;
}

int main(int argc, char *argv[]) { // Standard main heading.
    int sum;
    /* clock_t is the data type for storing timing information.
     * We must make two variables, one for the start and the other to capture
     * the difference.
     */
    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 1000; i < 60000; i += 1000) {
        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!
        sum = how_many_primes(i);

        // Capture the clock and subtract the start to get the total time elapsed.
        diff = clock() - start;

        //std::cout << "sum = " << sum << "\n";

        // Convert clock_t into seconds as a floating point number.
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

        // Print out first the size (i) and then the elapsed time.
        std::cout << i << " " << timeAmount << "\n";

        // We flush to ensure the timings is printed out.
        std::cout << std::flush;
    }

    return 0;
}

