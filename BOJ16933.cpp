//
// Created by 전형진 on 2020-03-08.
//
//
//
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
struct PER{
    int y;
    int x;
    int cnt;
    int dis;
};
int map[1001][1001];
int visit[1001][1001][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ans=9999;
int n,m,k;
int BFS(){
    queue<PER> q;
    q.push({0,0,0,1});
    visit[0][0][0] = 1;
    bool day = true;
    while(!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int y = q.front().y;
            int x = q.front().x;
            int cnt = q.front().cnt;
            int dis = q.front().dis;

            q.pop();
            if (y == n - 1 && x == m - 1) {
                return dis;
            }
            bool flag = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int ncnt = cnt + 1;
                int ndis = dis +1;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (map[ny][nx] == 0 && visit[ny][nx][cnt] == 0) {
                        visit[ny][nx][cnt] = 1;
                        q.push({ny, nx, cnt, ndis});
                    }
                    else if (map[ny][nx] == 1 && ncnt <= k && visit[ny][nx][ncnt] == 0) {
                         if(day) {
                             visit[ny][nx][ncnt] = 1;
                             q.push({ny, nx, ncnt,ndis});
                         }
                         else{
                                 q.push({y,x,cnt,ndis});
                         }
                    }
                }
            }
        }
        day = !day;
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