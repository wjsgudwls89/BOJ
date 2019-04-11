//
// Created by ÀüÇüÁø on 2019-04-11.
//
#include <stdio.h>
#include <queue>>
#include <vector>

using namespace std;
int l;
int startx,starty;
int endx,endy;
int cnt;
int map[301][301];
int dx[8] = {2,1,-1,-2,-2,-1, 2, 1};
int dy[8] = {1,2, 2, 1,-1,-2,-1,-2};
void initiate(int map[301][301]){
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            map[i][j] = 0;
        }
    }
}

void bfs(int y,int x){

    queue<int> xq;
    queue<int> yq;
    vector<int> v;
    map[y][x] = 1;
    xq.push(x);
    yq.push(y);

    while(!xq.empty()) {
        int qs = xq.size();
        while (qs--) {
            int x = xq.front();
            int y = yq.front();
            xq.pop();
            yq.pop();
            if (x == endx && y == endy) {
                printf("%d\n",cnt);
                cnt =0;
                return;
            }

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < l && ny < l && map[ny][nx] == 0) {
                    map[ny][nx] = 1;
                    xq.push(nx);
                    yq.push(ny);
                }
            }

        }
        cnt++;
    }
   // cnt =0;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&l);
        scanf("%d %d",&startx,&starty);
        scanf("%d %d",&endx,&endy);
        bfs(starty,startx);
        initiate(map);

    }

}