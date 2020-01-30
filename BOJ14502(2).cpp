//
// Created by 전형진 on 2020-01-30.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int map[8][8];
int temp[8][8];
int visit[8][8];
int cnt = 0;
int ans = 0;
vector<pair<int,int>>v;
queue<pair<int,int>> q;

void makeMap(int a[8][8],int b[8][8]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = b[i][j];
        }
    }
}
void bfs(){
    for (int i = 0; i < v.size(); ++i) {
        q.push({v[i].first,v[i].second});
    }

    while(!q.empty()){

        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x +dx[i];
            int ny = y +dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                q.push({ny,nx});
            }
        }

    }
}
void dfs(int depth){
    if(depth == 3){
        makeMap(visit,temp);
        bfs();
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(visit[i][j] == 0) cnt++;
            }
        }
        ans = max(cnt,ans);
        //printf("%d ",ans);
        return;
    }
    else{
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(temp[i][j] == 0){
                    temp[i][j] = 1;
                    dfs(depth+1);
                    temp[i][j] = 0;
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
            temp[i][j] = map[i][j];
            if(map[i][j] == 2){
                v.push_back({i,j});
                visit[i][j] =1;}
            if(map[i][j] == 1) visit[i][j] = 1;
        }
    }
    dfs(0);
    printf("%d",ans);
}