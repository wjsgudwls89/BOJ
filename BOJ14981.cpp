//
// Created by 전형진 on 2019-10-18.
//
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

int wh[4][8];

int visit[4];
void RIGHT(int idx){
    int temp;
    int arr[8];
    temp = wh[idx][7];
    for (int i = 0; i <7 ; ++i) {
        arr[i] = wh[idx][i];
    }
    for (int i = 0; i < 7; ++i) {
        wh[idx][i+1] = arr[i];
    }
    wh[idx][0] = temp;
}
void LEFT(int idx){
    int arr[8];
    int temp;
    temp = wh[idx][0];
    for (int i = 0; i < 7; ++i) {
        arr[i] = wh[idx][i+1];
    }
    for (int i = 0; i < 7; ++i) {
        wh[idx][i] = arr[i];
    }
    wh[idx][7] = temp;
}

int main(){
    int t;
    int idx;
    int dir;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf("%1d",&wh[i][j]);
        }
    }
    scanf("%d",&t);

    for (int i = 0; i < t; ++i) {
        memset(visit,0, sizeof(visit));
        scanf("%d %d",&idx,&dir);
        idx -= 1;
        visit[idx] = dir;
        for (int j = 0; j < 4; ++j) {
            if (idx + j + 1 < 4 && visit[idx + j + 1] == 0 &&
                wh[idx + j][2] != wh[idx + j + 1][6]) {
                if (visit[idx + j] == 1)
                    visit[idx + j + 1] = -1;
                else if (visit[idx + j] == -1) {
                    visit[idx + j + 1] = 1;
                }
            }
            if (idx - j - 1 >= 0 && visit[idx - j - 1] == 0 &&
                wh[idx - j][6] != wh[idx - j - 1][2]) {
                if (visit[idx - j] == 1)
                    visit[idx - j - 1] = -1;
                else if (visit[idx - j] == -1) {
                    visit[idx - j - 1] = 1;
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            if(visit[j] == 1)
            {
                RIGHT(j);
            }
            else if(visit[j] == -1){
                LEFT(j);
            }
        }
    }
    int sum = 0;
    if(wh[0][0] == 1) sum+=1;
    if(wh[1][0] == 1) sum+=2;
    if(wh[2][0] == 1) sum+=4;
    if(wh[3][0] == 1) sum+=8;

    printf("%d",sum);

}