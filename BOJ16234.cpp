//
// Created by 전형진 on 2019-07-17.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct Point{
    int x;
    int y;
};

vector<Point> v;
int map[51][51];
int visit[51][51];


int N,L,R;

void move(int y,int x){


    queue<int>xq;
    queue<int>yq;


    xq.push(x);
    yq.push(y);
    visit[y][x] = 1;

    while (!xq.empty())
    {
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        v.push_back({x,y});
        for (int i = 0; i < 4; ++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N
            &&visit[ny][nx] == 0) {
                if (abs(map[y][x] - map[ny][nx]) <= R
                && abs(map[y][x] - map[ny][nx]) >= L)
                {
                            xq.push(nx);
                            yq.push(ny);
                            visit[ny][nx] = 1;
                        }

                }
            }
        }
}

int main() {
    int sol = 0;
    bool end = false;
    scanf("%d %d %d", &N, &L, &R);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &map[r][c]);
        }
    }
    while (end == false) {
        bool happen = false;
        memset(visit, 0, sizeof(visit));
        int k = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visit[i][j] == 0) {
                    v.clear();
                    int sum = 0;
                    int cnt = 0;
                    int result = 0;

                    move(i, j);

                    if(v.size()>1){
                        happen = true;
                        for (int a = 0; a < v.size(); ++a) {
                            int x = v[a].x;
                            int y = v[a].y;

                            sum += map[y][x];
                            cnt++;
                        }
                        result = sum/cnt;

                        for (int a = 0; a < v.size(); ++a) {
                            int x = v[a].x;
                            int y = v[a].y;

                            map[y][x] = result;
                        }
                    }
                }
            }
        }

        if (happen == false)
            end = true;
        else {
            sol++;
        }
    }
    printf("%d",sol);
}