//
// Created by 전형진 on 2020-03-21.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct pos {
    int y;
    int x;
};
struct lq{
    int y;
    int x;
    int color;
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector <pos> v;
int n,m,r,g;
int map[51][51];
int temp[2501];
int visit[51][51];
int tvisit[51][51];
int tmap[51][51];
int color[51][51];
int rans;
int BFS(){
    queue <lq> q;
    int ans = 0;
    int cnt = 1;
    for (int i = 0; i < v.size(); ++i) {
        if(temp[i] == 2){
            q.push({v[i].y,v[i].x,1});
            color[v[i].y][v[i].x] = 1;
            visit[v[i].y][v[i].x] = 0;
        }
        else if(temp[i] == 1){
            q.push({v[i].y,v[i].x,2});
            color[v[i].y][v[i].x] = 2;
            visit[v[i].y][v[i].x] = 0;
        }
        else continue;
    }

    while(!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int y = q.front().y;
            int x = q.front().x;
            int col = q.front().color;
            q.pop();
            if(map[y][x] == 0) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] !=0) {

                    if (visit[ny][nx] == 0 && color[ny][nx] ==0){
                        visit[ny][nx] = cnt;
                        color[ny][nx] = col;
                        q.push({ny,nx,col});
                    }
                    else if(visit[ny][nx] == cnt){
                        if(color[ny][nx] != col && cnt) {
                            ans++;
                            map[ny][nx] = 0;
                           // printf("%d %d\n",ny,nx);
                        }
                    }
                }
            }
        }
        cnt++;

    }
    return ans;
}
void DFSG(int start, int depth){
    if(depth == g){
//        for (int i = 0; i < v.size(); ++i) {
//            printf("%d ",temp[i]);
//        }
//        printf("\n");
        memcpy(map,tmap, sizeof(tmap));
        memcpy(visit,tvisit, sizeof(visit));
        memset(color,0, sizeof(color));
        int temp = BFS();
       // printf("%d\n",temp);
        rans = max(rans,temp);
        return;
    }
    for (int i = start; i < v.size(); ++i) {
        if(temp[i] == 0){
            temp[i] = 2;
            DFSG(i+1,depth+1);
            temp[i] = 0;
        }
    }
}
void DFSR(int start ,int depth){
    if(depth == r){
        DFSG(0,0);
        return;
    }
    for (int i = start; i < v.size(); ++i) {
        if(temp[i] == 0){
            temp[i] = 1;
            DFSR(i+1,depth+1);
            temp[i] = 0;
        }
    }
}
int main(){

    scanf("%d %d %d %d",&n,&m,&g,&r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&tmap[i][j]);
                if(tmap[i][j] == 0) tvisit[i][j] = 0;

                if(tmap[i][j] == 2) v.push_back({i,j});
            }
        }
    DFSR(0,0);
    printf("%d",rans);
}