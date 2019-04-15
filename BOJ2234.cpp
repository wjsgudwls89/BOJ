//
// Created by 전형진 on 2019-04-12.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int map[51][51];
int visit[51][51];
int check[4];
int cnt =0;
int min;
int sizemin;
int m,n;
vector <int> v;

void clear(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visit[i][j] = 0;
        }
    }
}
void getCheck(int bit){
    for(int i=3 ;i>=0;i--){
        check[i] = bit%2;
        bit = bit/2;
    }
}
void bfs(int y, int x){
    queue <int> xq;
    queue <int> yq;

    visit[y][x] = true;
    xq.push(x);
    yq.push(y);

    int size = 0;
    while(!xq.empty()) {
        int y = yq.front();
        int x = xq.front();
        getCheck(map[y][x]);
        xq.pop();
        yq.pop();

        for (int i = 0; i < 4; i++) {
            if (check[i] == 0) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visit[ny][nx])
                {
                    visit[ny][nx] = true;
                    xq.push(nx);
                    yq.push(ny);

                }
            }
        }
        size++;
    }
    sizemin = max(sizemin,size);
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visit[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    printf("%d\n", sizemin);
    clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 8; k > 0; k = k / 2) {
                if (map[i][j] & k) {
                    int temp = map[i][j];
                    map[i][j] = map[i][j] - k;
                    bfs(i, j);
                    map[i][j] = temp;
                    clear();
                }
            }
        }
    }
    printf("%d", sizemin);
}