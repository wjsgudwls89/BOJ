////
//// Created by 전형진 on 2019-12-27.
////
#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[101][101];
int visit[101][101];
int tvisit[101][101];
int n;
int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};
int idx = 1;
int ans = 99999;
queue<pair<int,int>> tq;
int abfs(int temp){

    int cnt = 0;

    while(!tq.empty()) {
        int qs = tq.size();
        while (qs--) {
            int y = tq.front().first;
            int x = tq.front().second;

            tq.pop();

            if (visit[y][x] != 0 && visit[y][x] != temp) {
                return cnt;
            }

            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
                    if (visit[ny][nx] != temp && tvisit[ny][nx] == 0) {
                        tvisit[ny][nx] = 1;
                        tq.push({ny, nx});
                    }
                }
            }
        }
        cnt++;
    }
}
void bfs(int y,int x,int cnt) {
    queue<pair<int, int>> q;
    visit[y][x] = cnt;
    q.push({y, x});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] == 1) {
                if (visit[ny][nx] == 0) {
                    visit[ny][nx] = cnt;
                    q.push({ny, nx});

                }
            }
        }
    }
}

int main(){


    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&map[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(visit[i][j] == 0 && map[i][j] == 1){
                bfs(i,j,idx);
                idx++;
            }
        }
    }
    queue<pair<int,int>> xq;
    for (int k = 1; k <=idx-1 ; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(visit[i][j] == k){
                    tq.push({i,j});
                }
            }
        }

        memset(tvisit,0, sizeof(tvisit));
        ans = min(ans,abfs(k));
        tq = xq;
    }
    printf("%d",ans-1);
}