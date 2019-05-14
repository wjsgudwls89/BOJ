//
// Created by 전형진 on 2019-05-09.
//
#include <stdio.h>
#include <iostream>

int map[30][30];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int N;
double result  = 0;
double d[4];
void dfs(int y, int x,int cnt,double percent){
    if(cnt == N+1){
        result += percent;
        return;
    }
    map[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(map[ny][nx] == 0){
            dfs(ny,nx,cnt+1,percent*d[i]);
        }
    }
    map[y][x] = 0;
}
int main(){
    scanf("%d",&N);
    for (int i = 0; i < 4; ++i) {
        scanf("%lf",&d[i]);
        d[i] /=100;
    }
    dfs(14,14,1,1.0);
    printf("%.10lf",result);
}