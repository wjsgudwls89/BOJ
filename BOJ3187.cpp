//
// Created by 전형진 on 2020-03-04.
//
#include <iostream>
#include <queue>

using namespace std;

int r,c;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int scnt;
int wcnt;
char map[251][251];
int visit[251][251];
void BFS(int y,int x){
    int tw = 0;
    int ts = 0;
    if(map[y][x] == 'v') tw++;
    if(map[y][x] == 'k') ts++;
    queue<pair<int,int>> q;
    visit[y][x] = 1;
    q.push({y,x});

    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny >=0 && nx < c && ny < r && visit[ny][nx] == 0){
                if(map[ny][nx] == '.'){
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                }
                else if(map[ny][nx] == 'v'){
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                    tw++;
                }
                else if(map[ny][nx] == 'k'){
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                    ts++;
                }
            }
        }
    }

    if(ts>tw){
        ts = 0;
    }
    else{
        tw = 0;
    }
    scnt -= ts;
    wcnt -= tw;

}

int main(){
    scanf("%d %d",&r,&c);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>map[i][j];
            if(map[i][j] == '#') visit[i][j] = 1;
            else if(map[i][j] == 'v') wcnt++;
            else if(map[i][j] == 'k') scnt++;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(visit[i][j] == 0){
                BFS(i,j);
            }
        }
    }
    printf("%d %d",scnt,wcnt);
}