//
// Created by 전형진 on 2019-05-20.
//
#include <stdio.h>
#include <queue>

using namespace std;

struct BALL {
    int y;
    int x;
};

int n , m;
queue<BALL> red;
queue<BALL> blue;
char map[11][11];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int visit[11][11][11][11];
int cnt = 0;
int oy,ox;
bool flag = false;


int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
            scanf("%s",map[i]);
    }
    int ry =0,rx =0,by =0,bx =0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 'R') {
                ry = i;
                rx = j;
                red.push({i,j});
            }
            if(map[i][j] == 'B'){
                by = i;
                bx = j;
                blue.push({i,j});
            }
            if(map[i][j] =='O'){
                oy = i;
                ox = j;
            }
        }

    }
    visit[ry][rx][by][bx] = 1;

    while(!red.empty()){
        int qs = red.size();
        while(qs--)
        {
             ry = red.front().y;
             rx = red.front().x;
             by = blue.front().y;
             bx = blue.front().x;
            red.pop();blue.pop();

            if(cnt > 10)
                break;

            if(ry == oy && rx == ox){
                flag = true;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                int nbx = bx + dx[i];
                int nby = by + dy[i];

                while(1){
                    if(map[nry][nrx] == '#'){
                        nry -= dy[i];
                        nrx -= dx[i];
                        break;
                    }
                    if(map[nry][nrx] == 'O') break;
                    nrx += dx[i]; nry+=dy[i];
                }
                while(1)
                {
                    if(map[nby][nbx] == '#'){
                        nby -= dy[i];
                        nbx -= dx[i];
                        break;
                    }
                    if(map[nby][nbx] == 'O') break;
                    nbx += dx[i]; nby+=dy[i];
                }

                if(nby == oy && nbx == ox) continue;

                if(nrx == nbx && nry == nby){
                    switch(i){
                        case 0: rx > bx ? nrx++ : nbx++; break;
                        case 1: rx < bx ? nrx-- : nbx--; break;
                        case 2: ry > by ? nry++ : nby++; break;
                        case 3: ry < by ? nry-- : nby--; break;
                    }
                }

                if(visit[nry][nrx][nby][nbx]) {
                    continue;
                }
                    red.push({nry, nrx});
                    blue.push({nby, nbx});
                    visit[nry][nrx][nby][nbx] = 1;

            }
        }
        if(flag) break;
        else cnt++;
    }
    if(flag) {
        printf("%d", cnt);
    }
    else
        printf("-1");

}