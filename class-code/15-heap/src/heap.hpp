class Heap {
    private:
        int *arr;
        int size; //The total size of the array
        int heapSize; //The total size of the unsorted heap
    public:
        Heap();
        void add(const int val);
        int removeFirst();
};
