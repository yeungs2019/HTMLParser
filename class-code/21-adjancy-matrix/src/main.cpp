#include <iostream>
#include <queue>
#include <set>

int **am;
#define INT_MAX (9999)

const int size = 6;

void print(int **am, const int len) {
    for (int i = 0; i < len; i++) {
        printf("\t%d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d:", i);
        for (int j = 0; j < len; j++) {
            printf("\t%d", am[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int **am, const int len, int start, int end, int weight) {
    if (start < 0 || start >= len) { return; }
    if (end < 0 || end >= len) { return; }
    am[start][end] = weight;
}

void remove_edge(int **am, const int len, int start, int end) {
    add_edge(am, len, start, end, INT_MAX);
}

void breadth_first(int **am, const int len) {
    std::queue<int> to_visit;
    std::set<int> has_visited;

    for(int i = 0; i < len; i++) {
        to_visit.push(i);

        while (!to_visit.empty()) {
            int node = to_visit.front();
            to_visit.pop();

            if (has_visited.find(node) != has_visited.end()) {
                continue;
            }

            printf("%d ", node);
            //visit(node)


            for (int i = 0; i < len; i++) {
                if (am[node][i] > 0 && am[node][i] < 9999) {
                    to_visit.push(i);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    am = new int*[size];
    for (int i = 0; i < size; i++) {
        am[i] = new int[size];
        for (int j = 0; j < size; j++) {
            am[i][j] = INT_MAX;
        }
        am[i][i] = 0;
    }

    add_edge(am, size, 0, 1, 20);
    add_edge(am, size, 0, 3, 10);
    add_edge(am, size, 1, 2, 10);
    add_edge(am, size, 1, 3, 80);
    add_edge(am, size, 1, 4, 10);
    add_edge(am, size, 2, 3, 50);
    add_edge(am, size, 3, 0, 40);
    add_edge(am, size, 3, 4, 22);
    add_edge(am, size, 4, 2, 30);
    add_edge(am, size, 5, 0, 60);

    print(am, size);

    breadth_first(am, size);

    return 0;
}
