#include <iostream>
#include <list>

#define O (0)
#define W (-1)
#define V (-2)

int tmaze[10][10] = {
    { O, O, O, O, O, O, O, O, O, O},
    { O, O, O, O, O, O, O, O, O, O},
    { O, W, W, W, W, W, W, W, W, O},
    { O, O, O, O, O, O, O, O, W, O},
    { O, O, O, O, O, O, O, O, W, O},
    { O, O, O, O, O, O, O, O, W, O},
    { O, O, O, O, O, O, O, O, W, O},
    { O, O, O, O, O, O, O, O, W, O},
    { O, W, W, W, W, W, W, W, W, W},
    { O, O, O, O, O, O, O, O, O, O},
};

int **maze = NULL;

void setup(const int w, const int h) {
    maze = new int*[w];

    for (int i = 0; i < w; i++) {

        maze[i] = new int[h];

        for (int j = 0; j < h; j++) {
            maze[i][j] = tmaze[i][j];
        }
    }
}

void print(int **maze, const int w, const int h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            printf("%d\t", maze[i][j]);
        }
        printf("\n");
    }
}

int path_exists_depth(int **maze, const int w, const int h, int cx, int cy, int ex, int ey) {
    if (cx < 0 || cx >= w || cy < 0 || cy >= h) { return -1; }
    if (maze[cx][cy] == W || maze[cx][cy] == V) { return -1; }
    if (cx == ex && cy == ey) { return 1; }

    maze[cx][cy] = V;

    print(maze, w, h);
    printf("-------------------\n");

    if (path_exists_depth(maze, w, h, cx, cy + 1, ex, ey) != -1) { return 1; }
    if (path_exists_depth(maze, w, h, cx + 1, cy, ex, ey) != -1) { return 1; }
    if (path_exists_depth(maze, w, h, cx, cy - 1, ex, ey) != -1) { return 1; }
    if (path_exists_depth(maze, w, h, cx - 1, cy, ex, ey) != -1) { return 1; }

    return -1;
}

class Point {
    public:
        Point(const int _x, const int _y, const int _amt) { x = _x; y = _y; amt = _amt;}
        int x, y, amt;
};

int is_valid(int **maze, const int w, const int h, const int x, const int y) {
    if (x < 0 || x >= w || y < 0 || y >= h) { return 0; }
    if (maze[x][y] == W || maze[x][y] == V) { return 0; }
    return 1;
}

int path_exists_breadth(int **maze, const int w, const int h, int sx, int sy, int ex, int ey) {
    std::list<Point> to_visit;

    to_visit.push_back(Point(sx, sy, 0));

    while (!to_visit.empty()) {
        Point p = to_visit.front();
        to_visit.pop_front();

        // More code here NOW!
        if (is_valid(maze, w, h, p.x, p.y)) {
            if(p.x == ex && p.y == ey) {
                return p.amt;
            }

            maze[p.x][p.y] = V;

            printf("visiting: (%d, %d)\n", p.x, p.y);
            print(maze, w, h);
            printf("-------------------\n");

            to_visit.push_back(Point(p.x, p.y+1, p.amt + 1));
            to_visit.push_back(Point(p.x, p.y-1, p.amt + 1));
            to_visit.push_back(Point(p.x+1, p.y, p.amt + 1));
            to_visit.push_back(Point(p.x-1, p.y, p.amt + 1));
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    setup(10, 10);
    //printf("can we got from (0, 0) -> (2,2) ? %d\n", path_exists_depth(maze, 10, 10, 0, 0, 9, 9));
    printf("can we got from (0, 0) -> (2,2) ? %d\n", path_exists_breadth(maze, 10, 10, 0, 0, 9, 9));
    //printf("can we got from (0, 0) -> (2,2) ? %d\n", path_exists(maze, 0, 0, 2, 2));
    return 0;
}
