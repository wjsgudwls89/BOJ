//
// Created by 전형진 on 2020-02-27.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> v[51];
int visit[51];
vector<int> ans;
int arr[51];
int N;
int score = 9999;
int a,b;
int BFS(int start){
    int cnt = 0;
    queue<int> q;

    visit[start] = 1;
    q.push(start);

    while(!q.empty()) {

        int qs = q.size();

        while (qs--) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < v[x].size(); ++i) {
                int nx = v[x][i];

                if (visit[nx] == 0) {
                    visit[nx] = 1;
                    q.push(nx);
                }
            }
        }
        cnt++;
    }
    return cnt;
}
int main(){

    scanf("%d",&N);

    while(1){
        scanf("%d %d",&a,&b);
        if(a == -1 && b == -1){
            break;
        }else{
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for (int i = 1; i <= N; ++i) {
        memset(visit,0, sizeof(visit));
        arr[i] = BFS(i)-1;
        score = min(score,arr[i]);
        //printf("%d\n",score);
    }

    for (int i = 1; i <= N; ++i) {
        if(arr[i] == score){
            ans.push_back(i);
        }
    }
    printf("%d %d\n",score,ans.size());
    for (int j = 0; j < ans.size(); ++j) {
        printf("%d ",ans[j]);
    }
}