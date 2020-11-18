#include "MinimumOverlap.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

MinimumOverlap::MinimumOverlap(const std::string &setFile) {
    std::ifstream input(setFile);
    if(!input){
	std::cout << "File does not exist" << setFile << std::endl;
	std::cout << "I'm sorry" << std::endl;
    }
    if(input.is_open()){
	// iterate the file
	for(std::string com; getline(input, com);){
	     std::cout << "I don't know what I'm doing" << std::endl;
	}
    }
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<int> &cover, const bool &print) const {
}
