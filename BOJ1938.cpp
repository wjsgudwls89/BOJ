#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int DOWN = 0;
const int UP = 1;
const int RIHGT = 2;
const int LEFT = 3;

const int SHAPE = 2;

const int MAX = 51;
const int SIZE = 3;
const int DIR = 4;

typedef struct POINT {
    int x, y;
} Point;

typedef struct LOG {
    Point p[SIZE];
} Log;

typedef struct PATH {
    Log log;
    int d;
} Path;

int n;
int map[MAX][MAX];
bool flag[MAX][MAX][SHAPE];
Log start, dest;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_in_range (Log v) {

    for (int i = 0; i < SIZE; ++ i) {
        int x = v.p[i].x;
        int y = v.p[i].y;

        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= n) return false;
    }
    return true;
}

bool is_visit (Log v) {
    int check = 0;
    int shape = v.p[1].x - v.p[0].x;

    for (int i = 0; i < SIZE; ++ i) {
        int x = v.p[i].x;
        int y = v.p[i].y;

        if (flag[x][y][shape]) {
            check |= (1 << i);
        }
    }

    if (check == ((1 << SIZE) - 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool is_promising (Log v) {

    if (!is_in_range(v)) {
        return false;
    }

    for (int i = 0; i < SIZE; ++ i) {
        int x = v.p[i].x;
        int y = v.p[i].y;

        if (map[x][y]) return false;
    }

    return true;
}

bool is_arrive (Log u) {

    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        if (dest.p[i].x != x || dest.p[i].y != y) return false;
    }
    return true;
}

Log move (Log u, int dir) {
    Log v;

    for (int i = 0; i < SIZE; ++ i) {
        v.p[i].x = u.p[i].x + dx[dir];
        v.p[i].y = u.p[i].y + dy[dir];
    }

    return v;
}

Log rotate (Log u) {
    int shape;
    Log v = {
            {
                    {-1, -1},
                    {-1, -1},
                    {-1, -1}
            }
    };

    shape = u.p[1].x - u.p[0].x;

    switch (shape) {
        case 0: {
            if (is_promising(move(u, UP)) && is_promising(move(u, DOWN))) {
                v.p[0].x = u.p[0].x - 1;
                v.p[0].y = u.p[0].y + 1;
                v.p[1].x = u.p[1].x;
                v.p[1].y = u.p[1].y;
                v.p[2].x = u.p[2].x + 1;
                v.p[2].y = u.p[2].y - 1;
            }
            break;
        }
        case 1: {
            if (is_promising(move(u, LEFT)) && is_promising(move(u, RIHGT))) {
                v.p[0].x = u.p[0].x + 1;
                v.p[0].y = u.p[0].y - 1;
                v.p[1].x = u.p[1].x;
                v.p[1].y = u.p[1].y;
                v.p[2].x = u.p[2].x - 1;
                v.p[2].y = u.p[2].y + 1;
            }
            break;
        }
        default:
            break;
    }

    return v;
}

void visit (Log v) {
    int shape = v.p[1].x - v.p[0].x;

    for (int i = 0; i < SIZE; ++ i) {
        int x = v.p[i].x;
        int y = v.p[i].y;

        flag[x][y][shape] = true;
    }
}

int bfs (Log start) {
    queue<Path> que;

    visit(start);
    que.push({start, 0});

    while (!que.empty()) {
        Log u = que.front().log;
        int d = que.front().d;

        que.pop();

        if (is_arrive(u)) {
            return d;
        }

        for (int i = 0; i < DIR; ++ i) {
            Log v = move(u, i);

            if (!is_promising(v)) continue;
            if (is_visit(v)) continue;

            visit(v);
            que.push({v, d + 1});
        }

        /* Rotation */
        Log v = rotate(u);

        if (v.p[0].x != -1 && !is_visit(v)) {
            visit(v);
            que.push({v, d + 1});
        }
    }

    return 0;
}

int main (int argc, const char *argv[]) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string info;
    int i, j;

    cin >> n;

    i = j = 0;

    for (int x = 0; x < n; ++ x) {
        cin >> info;

        for (int y = 0; y < n; ++ y) {
            switch (info[y]) {
                case 'B': {
                    start.p[i].x = x;
                    start.p[i].y = y;
                    i ++;
                    break;
                }
                case 'E': {
                    dest.p[j].x = x;
                    dest.p[j].y = y;
                    j ++;
                    break;
                }
                case '1': {
                    map[x][y] = info[y] - '0';
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }

    cout << bfs(start) << '\n';

    return 0;
}