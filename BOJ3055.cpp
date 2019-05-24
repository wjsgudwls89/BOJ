//
// Created by 전형진 on 2019-05-23.
//
#include <stdio.h>
#include <queue>

using namespace std;

char map[51][51];

int visit[51][51];

struct PAIR{
    int y;
    int x;
};

PAIR w[2501];



int r, c;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int cy,cx;
int rsy,rsx;
int wy,wx;
int idx= 0;
queue<PAIR> wq;
queue<PAIR> sq;
int bfs(){

    int cnt = 0;

    //visit[rsy][rsx] = 1;

    for (int k = 0; k < idx; ++k) {
        wq.push({w[k].y,w[k].x});
        //visit[w[k].y][w[k].x] = 1;
    }

    while(!sq.empty()){

        int qw = wq.size();

        while(qw--) {

            int wy = wq.front().y;
            int wx = wq.front().x;
                wq.pop();

            for (int i = 0; i < 4; ++i) {
                int nwx = wx + dx[i];
                int nwy = wy + dy[i];


                if(nwx<0 || nwx >= c || nwy <0 || nwy >=r)
                    continue;
                if(map[nwy][nwx] =='*' || map[nwy][nwx] == 'D' || map[nwy][nwx] =='X')
                    continue;
                map[nwy][nwx] = '*';
                wq.push({nwy,nwx});

                }
            }

        int qs = sq.size();

        while(qs--) {

            int y = sq.front().y;
            int x = sq.front().x;
            if (y == cy && x == cx) {
                return cnt;
            }
            sq.pop();
            for (int i = 0; i < 4; ++i) {

                int ssy = y + dy[i];
                int ssx = x + dx[i];

                if(ssy < 0||ssy >=r ||ssx <0||ssx>= c)
                    continue;
                if(map[ssy][ssx] == 'X' || map[ssy][ssx] == '*')
                    continue;
                if(visit[ssy][ssx])
                    continue;

                visit[ssy][ssx] = 1;
                sq.push({ssy,ssx});

            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    scanf("%d %d",&r,&c);
    for (int i = 0; i < r; ++i) {
        scanf("%s",map[i]);
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(map[i][j] == 'D'){
                cy = i;
                cx = j;
            }
            else if(map[i][j] == '*'){
                w[idx].y = i;
                w[idx].x = j;
                idx++;
            }
             else if(map[i][j] == 'S'){
                rsy = i;
                rsx = j;
                sq.push({rsy,rsx});
                visit[rsy][rsx] =1;
            }
        }
    }
    int ans;

    ans = bfs();
    if(ans == -1){
        printf("KAKTUS");
    } else
        printf("%d",ans);

}