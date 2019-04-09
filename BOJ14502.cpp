//
// Created by 전형진 on 2019-04-09.
//
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int map[9][9];
int temp[9][9];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m;
int rmax =0
        ;
int max(int a, int b){
    if(a>b)
    return a;
    else
        return b;
}


void remap(int a[9][9], int b[9][9]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = b[i][j];
        }
    }
}
void bfs(){

    queue<int> xq;
    queue<int> yq;
    int rtemp[9][9];

    remap(rtemp,temp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rtemp[i][j] == 2) {
                xq.push(j);
                yq.push(i);
            }
        }
    }

    while(!xq.empty()){

        int y = yq.front();
        int x = xq.front();

        yq.pop();xq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(rtemp[ny][nx] == 0){
                    rtemp[ny][nx] = 2;
                    xq.push(nx);
                    yq.push(ny);
                }
            }
        }
    }
    int cnt =0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(rtemp[i][j] == 0)
                cnt++;
        }
    }
    rmax = max(rmax,cnt);
}

void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                dfs(cnt +1);
                temp[i][j] =0;
            }
        }
    }
}

int main(){

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 0) {
                remap(temp, map);
                temp[i][j] = 1;
                dfs(1);
                temp[i][j] =0;
            }
        }
    }

   printf("%d",rmax);

}