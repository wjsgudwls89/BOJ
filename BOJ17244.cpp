//
// Created by 전형진 on 2020-02-27.
//
#include <queue>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

char map[51][51];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int visit[51][51];
int tvisit[51][51];
bool flag = true;
int N,M;
int ey,ex;
int sy,sx;
int ans = 0;
struct TA{
    int y;
    int x;
    int idx;
};
int rans = 9999;
TA check[5];
TA temp[5];
int pvisit[5];
int idx = 0;

void BFS(int y,int x,int ty,int tx){

    queue<pair<int,int>> q;
    tvisit[y][x] = 1;
    q.push({y,x});

    while (!q.empty()) {
        int qs = q.size();
//        for (int ti = 0; ti < M; ++ti) {
//            for (int tj = 0; tj < N; ++tj) {
//                printf("%d ",tvisit[ti][tj]);
//            }
//            printf("\n");
//        }
//        printf("\n");

        //printf("%d\n",ans);
        while (qs--) {
            int y = q.front().first;
            int x = q.front().second;
            if (y == ty && x == tx) {

                //printf("%d\n",ans);
                return;
               // exit(1);

            }
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M && tvisit[ny][nx] == 0) {
                    tvisit[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
        ans++;
    }
}
void PER(int depth){
    if(depth == idx){

        ans = 0;
        memcpy(tvisit,visit, sizeof(visit));
        if(idx == 0){
            BFS(sy,sx,ey,ex);
            rans = min(ans,rans);
            return;
        }
        BFS(sy,sx,temp[0].y,temp[0].x);
        for (int i = 1; i < idx; ++i) {
            memcpy(tvisit,visit, sizeof(visit));
            BFS(temp[i-1].y,temp[i-1].x,temp[i].y,temp[i].x);
        }
        memcpy(tvisit,visit, sizeof(visit));
        BFS(temp[idx-1].y,temp[idx-1].x,ey,ex);

        rans = min(ans,rans);
        //printf("--------------\n");
        //printf("%d\n",rans);
        return;
    }
    else{
        for (int i = 0; i < idx; ++i) {
            if(pvisit[i] == 0){
                pvisit[i] = 1;
                temp[depth] = check[i];
                PER(depth+1);
                pvisit[i] = 0;
            }
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>map[i][j];
            if(map[i][j] == '#'){visit[i][j] = 1;tvisit[i][j] = 1;}
            if(map[i][j] == 'E') {ey = i; ex = j;}
            if(map[i][j] == 'S'){ sy = i; sx = j;}
            if(map[i][j] == 'X'){
                check[idx].y = i;
                check[idx].x = j;
                check[idx].idx = idx;
                idx++;
            }
        }
    }
    //BFS(sy,sx);
    PER(0);
    printf("%d",rans);
}