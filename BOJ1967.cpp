//
// Created by 전형진 on 2020-03-15.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

struct NODE{
    int n;
    int w;
};
using namespace std;
vector<NODE> v[10001];
int visit[10001];
int ans = 0;
int n;
int BFS(int start){
    int dis = 0;
    queue<NODE> q;
    visit[start] = 1;
    q.push({start,dis});

    while(!q.empty()){
        int x = q.front().n;
        int qdis = q.front().w;
        dis = max(dis,qdis);
        q.pop();

        for (int i = 0; i < v[x].size(); ++i) {
            int nx = v[x][i].n;
            int ndis = qdis + v[x][i].w;

            if(visit[nx] == 0){
                visit[nx] = 1;
                q.push({nx,ndis});
            }
        }
    }
    return dis;
}
int main(){
    int a,b,w;
    scanf("%d",&n);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d",&a,&b,&w);
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    for (int i = 1; i <=n ; ++i) {

            memset(visit,0, sizeof(visit));


                int temp = BFS(i);
                ans = max(ans,temp);
        }
    printf("%d",ans);
}