#ifndef STACK_HPP
#define STACK_HPP

class IntStack {
    public:
        IntStack();
        void push(const int val);
        int top();
        void pop();
    private:
        int *arr; //note this
        int memSize; // memory
        int stackLength; // size of array
        void doubleSize();
        void copy(int *ar, const int size);
};

#endif
