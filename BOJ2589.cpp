//
// Created by 전형진 on 2019-04-30.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m;
char map[51][51];
int maxs;
vector<int> v;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void bfs(int starty, int startx){
    int mins = 0;
    queue<int> xq;
    queue<int> yq;
    int check[51][51];
    xq.push(startx);
    yq.push(starty);
    memset(check,0, sizeof(check));
    check[starty][startx] = 1;

    while(!xq.empty()) {
        int qs = xq.size();
        while (qs--) {
            int x = xq.front();
            int y = yq.front();
            xq.pop();
            yq.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < m && nx >= 0 && ny < n && ny >= 0 &&
                    map[ny][nx] == 'L' && check[ny][nx] == 0) {
                    xq.push(nx);
                    yq.push(ny);
                    check[ny][nx] = 1;
                }
            }
        }
        mins++;
    }
    maxs = max(mins,maxs);
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s",map[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 'L'){
                bfs(i,j);
            }
        }
    }
    printf("%d",maxs-1);
}