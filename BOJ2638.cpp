//
// Created by 전형진 on 2020-04-29.
//
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int map[101][101];
int visit[101][101];
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct POS{
    int y;
    int x;
};

queue<POS> q;
queue<POS> mq;
void doMelt(){
    while(!mq.empty()){
        int y = mq.front().y;
        int x = mq.front().x;
        mq.pop();
        map[y][x] = 0;
    }
}
void getMelt(){
    int qs = q.size();
    while(qs--){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(map[ny][nx] == 0 && visit[ny][nx] == 1){
                cnt++;
            }
        }
        if(cnt>=1){
            mq.push({y,x});
        }
        else{
            q.push({y,x});
        }
    }
}
void airBFS(){
    queue<POS> tq;
    tq.push({0,0});
    visit[0][0] = 1;

    while(!tq.empty()){
        int y = tq.front().y;
        int x = tq.front().x;
        tq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx < m && ny < n){
                if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                    tq.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    int ans = 0;
    int ch = 0;
    while(true){
        memset(visit,0, sizeof(visit));
        airBFS();
        getMelt();
        ch = mq.size();
        doMelt();
        ans++;
        if(q.empty()){
            printf("%d\n%d",ans,ch);
            break;
        }
    }
}