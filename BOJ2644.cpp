//
// Created by 전형진 on 2019-05-01.
//
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int a, b;
int gx, gy;
int visit[101];
vector<int> v[101];
int cnt = 0;
int bfs(int x){
    queue<int> q;

    q.push(x);
    visit[x] = true;
    int k=0;
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int x = q.front();
            q.pop();
            if(x == b){
                return cnt;
            }
            for(int i=0;i<v[x].size();i++){
                int nx = v[x][i];
                if(visit[nx] == false){
                    q.push(nx);
                    visit[nx] = true;

                }
            }
        }
        cnt++;
        //printf("%d",cnt);
    }
    return -1;
}
int main() {
    int ans;


    scanf("%d", &n);

    scanf("%d %d", &a, &b);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &gx, &gy);
        v[gx].push_back(gy);
        v[gy].push_back(gx);
    }
    ans = bfs(a);
    if(ans !=0)
    printf("%d",ans);
    else
        printf("%d",-1);
}