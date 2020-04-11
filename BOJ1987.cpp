//
// Created by 전형진 on 2020-04-11.
//

#include <iostream>
#include <algorithm>

using namespace std;
int r,c;
char map[21][21];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int visit[27];
int ans;
void DFS(int y,int x,int cnt){
    if(ans < cnt)
        ans = cnt;
    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny>=0 && nx<c && ny<r){
            if(visit[map[ny][nx] - 'A'] == 0){
                visit[map[ny][nx] - 'A'] = 1;
                DFS(ny,nx,cnt+1);
                visit[map[ny][nx] - 'A'] = 0;
            }
        }
    }
}
int main(){
    cin>>r>>c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>map[i][j];
        }
    }
    visit[map[0][0]-'A'] = 1;
    DFS(0,0,1);
    printf("%d",ans);
}