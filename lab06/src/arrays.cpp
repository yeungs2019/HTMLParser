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
	int minOdd = 0;
	for (int i = 0; i < size; i++){
		if(minOdd > array[i]){
			minOdd = array[i];
		}
		return minOdd;
	}
    return -1;
}

int search(const int array[], int size, int value) {
    return 0;
}

bool remove(int array[], int size, int index) {
    return false;
}
