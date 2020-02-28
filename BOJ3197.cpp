//
// Created by 전형진 on 2020-02-27.
//
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int r,c;
bool flag = false;

char map[1501][1501];
int visit[1501][1501];

int dx[] ={1,0,-1,0};
int dy[] = {0,1,0,-1};

struct SWAN{
    int y;
    int x;
};
SWAN swan[2];
queue<pair <int,int>> SQ,SNQ,Q,NQ;

void Sbfs(){
    while(!SQ.empty() && !flag){
        int y = SQ.front().first;
        int x = SQ.front().second;
        SQ.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx>=0 && ny>=0 && nx<c && ny <r){
                if(visit[ny][nx] == 0)
                {
                    if(map[ny][nx] == '.'){
                        visit[ny][nx] = 1;
                        SQ.push({ny,nx});
                    }
                    else if(map[ny][nx] == 'L'){
                        visit[ny][nx] = 1;
                        flag = true;
                        break;
                    }
                    else if(map[ny][nx] == 'X'){
                        visit[ny][nx] = 1;
                        SNQ.push({ny,nx});
                    }
                }
            }
        }
    }
}
void Wbfs(){
    while (!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;

        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y +dy[i];
            int nx = x +dx[i];

            if(nx>=0 && ny >=0 && nx<c && ny<r){
                if(map[ny][nx] == 'X'){
                    map[ny][nx] = '.';
                    NQ.push({ny,nx});
                }
            }
        }
    }
}
int main(){
    int idx = 0;
    scanf("%d %d",&r,&c);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>map[i][j];

            if(map[i][j] != 'X') Q.push({i,j});
            if(map[i][j] == 'L'){
                swan[idx].y = i;
                swan[idx].x = j;
                idx++;
            }
        }
    }

        int time = 0;
        SQ.push({swan[0].y,swan[0].x});
        visit[swan[0].y][swan[0].x] = 1;

        while(!flag) {
            Sbfs();
            if (!flag) {

                Wbfs();
                Q = NQ;
                SQ = SNQ;

                while (NQ.empty() == 0) NQ.pop();
                while (SNQ.empty() == 0) SNQ.pop();
                time++;
            }
        }

        printf("%d",time);

}