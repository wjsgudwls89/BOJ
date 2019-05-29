//
// Created by 전형진 on 2019-05-29.
//
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int map[301][301];
int melt[301][301];
int visit[301][301];

int n,m;

void sbfs(int y, int x){

    queue<int> xq;
    queue<int> yq;

    visit[y][x] = 1;
    xq.push(x);
    yq.push(y);

    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        int nx,ny;
        for (int i = 0; i < 4; ++i) {
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx >= 0 && nx <m && ny >=0 && ny<n
               &&map[ny][nx] != 0 && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                xq.push(nx);
                yq.push(ny);
            }
        }
    }
}
void bfs(int y, int x){
    int cnt = 0;

    queue<int> xq;
    queue<int> yq;

    visit[y][x] = 1;
    xq.push(x);
    yq.push(y);

    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        int nx,ny;
        for (int i = 0; i < 4; ++i) {
             nx = x+dx[i];
             ny = y+dy[i];
            if(nx >= 0 && nx <m && ny >=0 && ny<n
            && map[ny][nx] == 0){
                cnt++;
            }
        }
        melt[y][x] = cnt;
        cnt = 0;
        for (int i = 0; i < 4; ++i) {
             nx = x+dx[i];
             ny = y+dy[i];
            if(nx >= 0 && nx <m && ny >=0 && ny<n
               &&map[ny][nx] != 0 && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                xq.push(nx);
                yq.push(ny);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            map[i][j] -= melt[i][j];
            melt[i][j] = 0;
            if(map[i][j] < 0) {
                map[i][j] = 0;
            }
        }
    }
}
int main() {
    bool flag = false;
    int ans = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    int year = 0;
    while (!flag) {
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] != 0 && visit[i][j] == 0) {
                    bfs(i, j);
                    year++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                visit[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] != 0 && visit[i][j] == 0) {
                    sbfs(i, j);
                    ans++;
                    if (ans == 2) {
                        printf("%d", year);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        ans=0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    visit[i][j] = 0;
                    if(map[i][j] == 0)
                        cnt++;
                }
            }
            if(cnt == n*m) {
                printf("0");
                break;
            }

        }
    }

