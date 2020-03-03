#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> v[101];

int visit[101];
int ans[101];
int n,m;
int a,b;

int BFS(int start,int end){
    int cnt = 0;
    queue<int> q;
    visit[start] = 1;
    q.push(start);

    while(!q.empty()){
        int qs = q.size();
        while(qs--) {
            int x = q.front();
            q.pop();
            if(x == end){
                return cnt;
            }
            for (int i = 0; i < v[x].size(); ++i) {
                int nx = v[x][i];

                if(visit[nx] == 0){
                    visit[nx] = 1;
                    q.push(nx);
                }
            }
        }
        cnt++;
    }
}
int main(){
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            if(i == j) continue;
            else{
                memset(visit,0, sizeof(visit));
                ans[i] += BFS(i,j);
            }
        }
    }
//    for (int i = 1; i <=n ; ++i) {
//        printf("%d ",ans[i]);
//    }
    int minidx = 0;
    int min = 9999999;
    for (int i = 1; i <=n ; ++i) {
        if(ans[i] < min){
            min = ans[i];
            minidx = i;
        }
    }
    printf("%d",minidx);
}
