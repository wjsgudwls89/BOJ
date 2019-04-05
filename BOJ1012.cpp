//
// Created by 전형진 on 2019-04-05.
//

#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;
int t,m,n,k,x,y;
int veg[51][51];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int cnt= 0;
void bfs(int sy,int sx){
    queue<int> xq;
    queue<int> yq;

    xq.push(sx);yq.push(sy);
    veg[sy][sx] = 0;


    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<m && ny>=0 && ny<n && veg[ny][nx] == 1){
                veg[ny][nx] = 0;
                xq.push(nx);
                yq.push(ny);
            }
        }
    }
}
int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            int vx = x;
            int vy = y;
            veg[vy][vx] = 1;
            if(i==k-1)
                printf("\n");
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (veg[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        cnt =0;
    }
}