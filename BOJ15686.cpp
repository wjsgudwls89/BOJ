//
// Created by 전형진 on 2019-04-12.
//
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n,m;
int map[51][51];

int visit[14];
int k=0;
int homec=0;
vector<int> v;
int sum=0;
struct chicken{
    int x;
    int y;
};
struct chicken c[14];
struct home{
    int x;
    int y;
};
struct home h[2501];


void dfs(int start,int cnt){
    if(cnt == m) {
        int dis[51][51];
        int temp[51][51];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i][j] = 99999;
            }
        }
        for(int i=0;i<k;i++){
            if(visit[i] == true){
                for(int j=0;j<homec;j++){
                    dis[h[j].y][h[j].x]
                    =abs(h[j].x-c[i].x)+abs(h[j].y-c[i].y);
                    if(dis[h[j].y][h[j].x] < temp[h[j].y][h[j].x])
                        temp[h[j].y][h[j].x]=dis[h[j].y][h[j].x];
                }
            }
            else
                continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j] != 99999)
                    sum+=temp[i][j];
            }
        }
        v.push_back(sum);
        sum=0;
    }
    else
    {
        for(int i = start;i<k;i++)
        {
            if(visit[i] == false) {
                visit[i] = true;
                dfs(i+1,cnt+1);
                visit[i] = false;
            }
        }
    }
}
int main(){

    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2) {
                c[k].x = j;
                c[k].y = i;
                k++;
            }
            if(map[i][j] == 1){
                h[homec].x = j;
                h[homec].y = i;
                homec++;
            }
        }
    }
    dfs(0,0);

    sort(v.begin(),v.end());
    printf("%d",v[0]);

}
