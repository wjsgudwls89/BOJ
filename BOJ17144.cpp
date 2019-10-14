//
// Created by 전형진 on 2019-10-14.
//
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct DUST{
    int y;
    int x;
};
DUST dust[2501];
int map[51][51];
int dustmap[51][51];
int r,c,t;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int mx[2],my[2];
queue<int> xq;
queue<int> yq;
int getSum(){
    int sum = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(map[i][j]>0){
                sum+=map[i][j];
            }
        }
    }
    return sum;
}
void move(){
    int ny = my[0];
    int nx = mx[0];
    int idx = 0;
    int t = 0;
    while(1){

        ny += dy[idx], nx+=dx[idx];

        if(ny < 0 || nx< 0 || ny >=r || nx >= c){
            ny -= dy[idx], nx -=dx[idx];
            if(idx == 0)
                idx = 3;
            else if(idx == 3) {
                idx = 2;
            }
            else if(idx == 2) {
                idx = 1;
            }
            continue;
        }
        if(ny == my[0] && nx == mx[0])
            break;
        int temp = map[ny][nx];
        map[ny][nx] = t;
        t = temp;
    }
     ny = my[1];
     nx = mx[1];
     idx = 0;
     t = 0;
    while(1){

        ny += dy[idx], nx+=dx[idx];

        if(ny < 0 || nx< 0 || ny >=r || nx >= c){
            ny -= dy[idx], nx -=dx[idx];
            if(idx == 0)
                idx = 1;
            else if(idx == 1) {
                idx = 2;
            }
            else if(idx == 2) {
                idx = 3;
            }
            continue;
        }
        if(ny == my[1] && nx == mx[1])
            break;
        int temp = map[ny][nx];
        map[ny][nx] = t;
        t = temp;
    }
}

void findDust(){
    int idx = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(map[i][j] > 0){
                dust[idx].y = i;
                dust[idx].x = j;
                xq.push(dust[idx].x);
                yq.push(dust[idx].y);
                idx++;
            }
        }
    }
}

void spread() {
    memset(dustmap,0, sizeof(dustmap));
    while (!xq.empty()) {
        int x = xq.front();
        int y = yq.front();
        xq.pop();
        yq.pop();

        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < c && ny >= 0 && ny < r && map[ny][nx] != -1) {
                cnt++;
                dustmap[ny][nx] += map[y][x] / 5;
            }

        }
        dustmap[y][x] += map[y][x] - ((map[y][x] / 5) * cnt);
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            map[i][j] = dustmap[i][j];

        }
    }
    map[my[0]][mx[0]] = -1;
    map[my[1]][mx[1]] = -1;
}
int main(){
    scanf("%d %d %d",&r,&c,&t);
    int idx = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == -1){
                mx[idx] = j;
                my[idx] = i;
                dustmap[i][j] = -1;
                idx++;
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        findDust();
        spread();
        move();
    }
    int ans = 0;
    ans = getSum();
    printf("%d",ans);
}