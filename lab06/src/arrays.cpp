int countNegatives(const int array[], int size) {
	int negNum = 0;
	for (int i = 0; i < size; i++){
		if (array[i] < 0){
			negNum++;
		}
	}
    return negNum;
}

int findMinOdd(const int array[], int size) {
	int minOdd;
	for (int i = 0; i < size; i++){
		if (array[i] % 2 != 0 && (array[i] < minOdd)){
			minOdd = array[i];
			return minOdd;
		}
	}
	return -1;
}

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
			if (array[i] == index) {
				size = size - 1;
					for (int j = i; j < size; j++){
						array[j] = array[j + 1];
							if (0 <= index && index < size) {
								return true;
				}
			}
		}
	}
}
    return false;
}

