//
// Created by 전형진 on 2019-05-01.
//
#include <stdio.h>
#include <queue>

using namespace std;
char color[101][101];
char wcolor[101][101];
int visit[101][101];
int wvisit[101][101];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void nbfs(int y, int x,char c){
    queue<int> xq;
    queue<int> yq;

    xq.push(x);
    yq.push(y);
    visit[y][x] = true;

    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 &&nx<n && ny>=0 && ny<n
            && color[ny][nx] == c && !visit[ny][nx]){
                xq.push(nx);
                yq.push(ny);
                visit[ny][nx] = true;
            }

        }
    }
}
void wbfs(int y, int x,char c){
    queue<int> xq;
    queue<int> yq;

    xq.push(x);
    yq.push(y);
    wvisit[y][x] = true;

    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 &&nx<n && ny>=0 && ny<n
               && wcolor[ny][nx] == c  && !wvisit[ny][nx]){
                xq.push(nx);
                yq.push(ny);
                wvisit[ny][nx] = true;
            }
        }
    }
}
int main(){
    int cnt = 0;
    int cnt2=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",color[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            wcolor[i][j] = color[i][j];
            if(color[i][j] == 'G')
                wcolor[i][j] = 'R';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(color[i][j] == 'R' && visit[i][j] == 0){
                nbfs(i,j,'R');
                cnt++;
            }
            if(color[i][j] == 'G' && visit[i][j] == 0){
                nbfs(i,j,'G');
                cnt++;
            }
            if(color[i][j] == 'B' && visit[i][j] == 0){
                nbfs(i,j,'B');
                cnt++;
            }
            if(wcolor[i][j] == 'R' && wvisit[i][j] == 0){
                wbfs(i,j,'R');
                cnt2++;
            }
            if(wcolor[i][j] == 'B' && wvisit[i][j] == 0){
                wbfs(i,j,'B');
                cnt2++;
            }
        }
    }
    printf("%d %d",cnt,cnt2);
}