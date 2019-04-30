//
// Created by 전형진 on 2019-04-30.
//
#include <stdio.h>
#include <queue>
using namespace std;
int box[101][101][101];
int visit[101][101][101];
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};
int m,n,h;
int day = 0;
void bfs(){
    queue<int> xq;
    queue<int> yq;
    queue<int> zq;

    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (box[k][i][j] == 1) {
                    xq.push(j);
                    yq.push(i);
                    zq.push(k);
                }
            }
        }
    }
    while(!xq.empty()) {
        int qs = xq.size();
        while (qs--) {
            int x = xq.front();
            int y = yq.front();
            int z = zq.front();

            xq.pop();
            yq.pop();
            zq.pop();

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (nx < m && nx >= 0 && ny < n && ny >= 0 && nz < h && nz >= 0
                    && box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    xq.push(nx);
                    yq.push(ny);
                    zq.push(nz);
                }
            }
        }
        day++;
    }
}

int main(){
    scanf("%d %d %d",&m,&n,&h);

    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d",&box[k][i][j]);
            }
        }
    }
    bfs();
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               if(box[k][i][j] == 0) {
                   printf("%d", -1);
                   return 0;
               }
            }
        }
    }
    printf("%d",day-1);
}