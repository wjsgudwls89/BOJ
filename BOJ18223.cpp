//
// Created by 전형진 on 2019-12-27.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 987654321

using namespace std;

struct VERTEX{
    int a;
    int b;
};
vector <VERTEX> v[5001];
vector <int> path[5001];

int V,e,p;
int a,b,c;
bool find(int v){
    bool flag;

    if(v==1){
        return false;
    }
    for(int i = 0; i < path[v].size(); ++i) {
        int prev = path[v][i];

        if(prev == p)return true;
        else{
            flag = find(prev);
        }
    }
    return flag;
}
bool bfs(int start){
    bool flag;
    int dis[5001];
    priority_queue<pair<int,int>> q;

   fill(dis,dis+V+1,INF);
    dis[start] = 0;
    for (int i = 1; i <= V ; ++i) {
        q.push({-dis[i],i});
    }

    while(!q.empty()){
        int x = q.top().second;
        int y = -q.top().first;
        q.pop();

        if(y > dis[x]) continue;

        for(int i = 0; i < v[x].size(); ++i) {
            int next = v[x][i].a;
            int nextdis = v[x][i].b;

            if(dis[next] >= dis[x]+nextdis){
                dis[next] = dis[x]+ nextdis;
                q.push({-dis[next],next});
                path[next].push_back(x);
            }
        }
    }
    flag = find(V);

    return flag;

}

int main(){
    scanf("%d %d %d",&V,&e,&p);
    for (int i = 0; i < e; ++i) {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    path[1].push_back(0);

    if(bfs(1))
        printf("SAVE HIM");
    else
    {
        printf("GOOD BYE");
    }

}