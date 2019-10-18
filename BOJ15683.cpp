//
// Created by 전형진 on 2019-10-17.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct CCTV{
    int y;
    int x;
    int num;
};
CCTV tv[8];
int dx[4];
int dy[4];
int map[9][9];
int visit[9][9];
int temp[9][9];
int ctemp[9][9];
int check[5];
int roll[8];
int arr[8];
int n,m;
int idx;
int sol = 9999;
int ans = 9999;
queue<int> xq;
queue<int> yq;
queue<int> numq;
int count(){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(ctemp[i][j] == 0 && map[i][j] != 6)
                cnt++;
        }
    }
    return cnt;
}
void changeDir(int i,int tvnum){
    if(tvnum == 1) {
        if (i == 0) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = 0;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 1) {
            dx[0] = 0; dy[0] = -1;
            dx[1] = 0; dy[1] = 0;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 2) {
            dx[0] = -1; dy[0] = 0;
            dx[1] = 0; dy[1] = 0;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 3) {
            dx[0] = 0; dy[0] = 1;
            dx[1] = 0; dy[1] = 0;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
    }
    if(tvnum == 2) {
        if (i == 0) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = -1; dy[1] = 0;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 1) {
            dx[0] = 0; dy[0] = 1;
            dx[1] = 0; dy[1] = -1;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
    }
    if(tvnum == 3) {
        if (i == 0) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = -1;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 1) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = 1;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 2) {
            dx[0] = -1; dy[0] = 0;
            dx[1] = 0; dy[1] = 1;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 3) {
            dx[0] = -1; dy[0] = 0;
            dx[1] = 0; dy[1] = -1;
            dx[2] = 0; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
    }
    if(tvnum == 4) {
        if (i == 0) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = -1;
            dx[2] = -1; dy[2] = 0;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 1) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = -1;
            dx[2] = 0; dy[2] = 1;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 2) {
            dx[0] = -1; dy[0] = 0;
            dx[1] = 1; dy[1] = 0;
            dx[2] = 0; dy[2] = 1;
            dx[3] = 0; dy[3] = 0;
        }
        if (i == 3) {
            dx[0] = -1; dy[0] = 0;
            dx[1] = 0; dy[1] = 1;
            dx[2] = 0; dy[2] = -1;
            dx[3] = 0; dy[3] = 0;
        }
    }
    if(tvnum == 5) {
        if (i == 0) {
            dx[0] = 1; dy[0] = 0;
            dx[1] = 0; dy[1] = 1;
            dx[2] = -1; dy[2] = 0;
            dx[3] = 0; dy[3] = -1;
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            printf("%d ",visit[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
}


void spread(int y,int x,int ady,int adx) {
    visit[y][x] = 1;
    if (map[y][x] == 6)
        return;
    else {
            int ny = y + ady;
            int nx = x + adx;
            if(ny< n && nx < m && nx>= 0 && ny>=0 && visit[ny][nx] ==0 && map[ny][nx] != 6){
                visit[ny][nx] = 1;
                spread(ny, nx, ady, adx);
            }
        }
}
void dfs(int start,int depth) {
    if (depth == idx) {
        memcpy(ctemp,temp, sizeof(temp));
        ans = 9999;
        for (int i = 0; i < idx; ++i) {
            memcpy(visit,temp, sizeof(temp));
            changeDir(arr[i],tv[i].num);
            for (int j = 0; j < 4; ++j) {
                spread(tv[i].y, tv[i].x,dy[j],dx[j]);
            }

            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    if(ctemp[k][l] == 0 && visit[k][l] == 1)
                        ctemp[k][l] = 1;
                    else
                        continue;
                }
            }
        }
        ans = count();
        sol = min(ans,sol);

        return;
    }
    else{
        for (int i = start; i < idx; ++i) {
            for (int j = 0; j < roll[i]; ++j) {
                if(check[i] == 0) {
                    check[i] = 1;
                    arr[depth] = j;
                    dfs(start+1,depth + 1);
                    check[i] = 0;
                }
            }
        }
    }
}
int main(){
    idx= 0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 6){
                temp[i][j] = 1;
            }
            if(map[i][j] > 0 && map[i][j] != 6){
                tv[idx].num = map[i][j];
                tv[idx].y = i;
                tv[idx].x = j;
                idx++;
                //printf("%d\n",idx);
            }
        }
    }
    for (int i = 0; i < idx; ++i) {
        if (tv[i].num == 2)
            roll[i] = 2;
        else if (tv[i].num == 5)
            roll[i] = 1;
        else
            roll[i] = 4;
    }
    dfs(0,0);
    printf("%d",sol);
}