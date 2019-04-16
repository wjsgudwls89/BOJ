//
// Created by 전형진 on 2019-04-16.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int map[51][51];
int visit[51][51];
int check[10];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int idx = 0;
int getmax = 99999;
int temp[51][51];

struct virus{
    int x;
    int y;
};

virus vi[10];

void clean(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visit[i][j] = 0;
        }
    }
}

void bfs(int temps[51][51]){
    queue<int> xq;
    queue<int> yq;
    int cnts = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(temps[i][j] == 2) {
                xq.push(j);
                yq.push(i);
                visit[i][j] = 1;
            }
        }
    }
    while(!xq.empty()) {
        int qs = xq.size();
        while (qs--) {
            int x = xq.front();
            int y = yq.front();
            xq.pop();
            yq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                temps[ny][nx] == 0 && !visit[ny][nx])
                {
                    visit[ny][nx] = 1;
                    temps[ny][nx] =3;
                    xq.push(nx);
                    yq.push(ny);
                }
            }
        }
        cnts++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(temps[i][j] == 0) {
                cnts = 99999;
                break;
            }
        }
    }
        getmax = min(getmax, cnts);
    clean();
}

void dfs(int start, int cnt){
    if(cnt == m){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i][j] = map[i][j];
            }
        }
        for(int i=0;i<idx;i++){
            if(check[i] == 0)
                temp[vi[i].y][vi[i].x]=0;
        }
        bfs(temp);
        return;
    }
    else
        {
        for(int i = start ; i<idx;i++){
            if(check[i] == 0){
                check[i] = 1;
                dfs(start+1,cnt+1);
                check[i] = 0;
            }
        }
    }
}


int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2){
                vi[idx].x = j;
                vi[idx].y = i;
                idx++;
            }
        }
    }
    dfs(0,0);

    if(getmax == 99999){
        printf("%d",-1);
    }
    else
        printf("%d",getmax-1);
    return 0;
}