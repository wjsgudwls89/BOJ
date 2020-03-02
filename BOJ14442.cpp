//
// Created by 전형진 on 2020-03-02.
//
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
struct PER{
    int y;
    int x;
    int cnt;
};
int map[1001][1001];
int visit[1001][1001][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ans=9999;
int n,m,k;
int BFS(){
    queue<PER> q;
    q.push({0,0,0});
    visit[0][0][0] = 1;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;

        q.pop();
        if(y == n-1 && x == m-1){
            return visit[y][x][cnt];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            int ncnt = cnt+1;


            if(nx>=0 && ny>=0 && nx<m && ny<n && visit[ny][nx][cnt] == 0){
                if(map[ny][nx] == 0){
                    visit[ny][nx][cnt] = visit[y][x][cnt] +1;
                    q.push({ny,nx,cnt});
                }
                else if(map[ny][nx] == 1 && ncnt<=k){
                    visit[ny][nx][ncnt] = visit[y][x][cnt] +1;
                    q.push({ny,nx,ncnt});
                }

            }
        }

    }
    return -1;
}
int main(){
    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d",&map[i][j]);
        }
    }
    printf("%d",BFS());

}