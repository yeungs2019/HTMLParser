#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>

void print(const int val) {
    printf("%d ", val);
}

void print_vector(std::vector<int> v) {
    /*
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    */
    /*
    for (auto i = v.begin(); i != v.end(); i++) {
        printf("%d ", *i);
    }
    printf("\n");
    */
    std::for_each(v.begin(), v.end(), print);
    printf("\n");
}

void print_list(std::list<int> l) {
    std::for_each(l.begin(), l.end(), print);
    printf("\n");
}

void vector_fun() {
    int array[5] = {12, 7, 9, 21, 13};
    std::vector<int> v(array, array + 5);
    print_vector(v);
    v.pop_back();
    print_vector(v);
    v.push_back(15);
    print_vector(v);
}

class squared_sum {
    public:
        int operator()(int n1, int n2) { return n1 + n2*n2; }
};

void list_fun() {
    int array[5] = {12, 7, 9, 21, 13};
    std::list<int> l(array, array + 5);
    print_list(l);
    l.pop_back();
    print_list(l);
    l.push_back(15);
    print_list(l);
    l.pop_front();
    print_list(l);
    l.push_front(150);
    print_list(l);
    l.sort(std::greater<int>());
    print_list(l);
    int sum = std::accumulate(l.begin(), l.end(), 0, std::plus<int>());
    printf("sum = %d\n", sum);
    int sqsum = std::accumulate(l.begin(), l.end(), 0, squared_sum());
    printf("sqsum = %d\n", sqsum);
}

int main(int argc, char *argv[]) {
    //vector_fun();
    list_fun();
    return 0;
}
