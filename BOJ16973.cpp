//
// Created by 전형진 on 2020-03-26.
//
#include <stdio.h>
#include <queue>

using namespace std;

int map[1001][1001];
int visit[1001][1001];
int temp[1001][1001];

int n,m,h,w,sx,sy,fx,fy;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct POS{
    int y;
    int x;
    int dis;
};

bool check(int y,int x){


        for (int i = y; i < y + h; ++i) {
            if(i < 0 || i >= n || map[i][x] == 1) return false;
            if(x + w > m || map[i][x+w-1] == 1) return false;
        }
        for (int i = x; i < x + w; ++i) {
            if(i < 0 || i >= m || map[y][i] == 1) return false;
            if(y + h > n || map[y+h-1][i] == 1) return false;
        }

        return true;

}

int BFS(int sy,int sx){
    queue<POS> q;
    visit[sy][sx] = 1;
    q.push({sy,sx,0});

    while(!q.empty()) {


            int y = q.front().y;
            int x = q.front().x;
            int dis = q.front().dis;

            if( y == fy-1 && x == fx-1){
                return dis;
            }

            q.pop();

            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                int ndis = dis + 1;

                if(ny + h > n || nx + w > m) continue;

                if (ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] == 0 && visit[ny][nx] == 0) {

                    if (check(ny, nx)) {
                        visit[ny][nx] = 1;
                        q.push({ny, nx, ndis});
                    } else {
                        continue;
                    }
                }
            }


    }
    return -1;
}

int main(){
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1) visit[i][j] = 1;
        }
    }
    scanf("%d %d %d %d %d %d",&h,&w,&sy,&sx,&fy,&fx);

    printf("%d",BFS(sy-1,sx-1));

}
