int countNegatives(const int array[], int size) {
	int negNum = 0;
	for (int i = 0; i < size; i++){
		if (array[i] < 0){
			negNum++;
		}
	}
    return negNum;
} // from https://www.geeksforgeeks.org/c-program-to-count-positive-and-negative-numbers-in-an-array

int findMinOdd(const int array[], int size) {
	int minOdd;
	for (int i = 0; i < size; i++){
		if (array[i] % 2 != 0 && (array[i] < minOdd)){
			minOdd = array[i];
			return minOdd;
		}
	}
	return -1;
}// from https://www.geeksforgeeks.org/c-program-for-find-the-number-occurring-odd-number-of-times


int search(const int array[], int size, int value) {
	for (int i = 0; i < size; i++){
		if (array[i] == value){
			return i;
		}
	}
    return -1;
}

bool remove(int array[], int size, int index) {
	// Searches for the index
	for (int i = 0; i < size; i++) {
		if (array[i] == index){
			for (int i = index - 1; i < size; i++){
				array[index] = array[index + 1];
			}
			size--;
		}
	}
	if (0 <= index && index < size){
		return true;
	}
    return false;
} //from www.cprogrammingcode.com/2012/05/write-program-to-delete-element-from.html

