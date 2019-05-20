//
// Created by 전형진 on 2019-05-20.
//
#include <stdio.h>
#include <queue>

using namespace std;
vector <int> c;
int check[1000001];

int F,S,G,U,D;
int dx[] = {U,D};
int bfs(int start, int end){
    int cnt = 0;
    queue<int> q;
    q.push(start);
    check[start] = start;

    while(!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int x = q.front();
            q.pop();
            if(x == end){
                //printf("%d",cnt);
                return cnt;
            }
            int nx;
            for (int i = 0; i < 2; ++i) {
                if (i == 0)
                    nx = x + U;
                else
                    nx = x - D;

                if (check[nx] != nx && nx > 0 && nx <= 1000000) {
                    q.push(nx);
                    check[nx] = nx;

                }
            }
        }
        cnt++;
    }
    return -1;
}
int main(){
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
    int ans = bfs(S,G);
    if(ans != -1) {
        printf("%d", ans);
    } else printf("use the stairs");
}