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
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			break;
		}
	}
	if (i < size) {
		size = size -1;
		for (int j = i; j < size; j++) {
			array[i] = array[j-1];
		}
		return true;
	}
    return false;
}

