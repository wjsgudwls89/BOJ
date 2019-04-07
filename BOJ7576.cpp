//
// Created by 전형진 on 2019-04-05.
//
#include <stdio.h>
#include <queue>
using namespace std;
int tom[1001][1001];
int visit[1001][1001];
int m,n;
int cnt =0;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
queue<int> xq;
queue<int> yq;
void bfs(int y,int x) {


    //xq.push(x);
    //yq.push(y);
    visit[y][x] = 1;

    while (!yq.empty()) {
        int qs = yq.size();
        while (qs--) {
            int x = xq.front();
            int y = yq.front();
            xq.pop();
            yq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && tom[ny][nx] == 0
                    && visit[ny][nx] == 0) {
                    //tom[ny][nx] = 3;
                    visit[ny][nx] = 1;
                    xq.push(nx);
                    yq.push(ny);
                }
            }
        }
        cnt++;
    }
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tom[i][j]);
            if(tom[i][j] == 1){
                xq.push(j);
                yq.push(i);
            }

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tom[i][j] == 1)
                bfs(i,j);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j] == 0 && tom[i][j] == 0) {
                printf("-1");
                return 0;
            }

        }
    }
    printf("%d",cnt-1);
}