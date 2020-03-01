//
// Created by 전형진 on 2020-02-28.
//
#include <stdio.h>
#include <algorithm>
#include <cstring>

int k;
using namespace std;
int bat[50][9];
int visit[9];
int rtemp[9];
int score = 0;
int cnt = 0;
int base[4];

int n;

int iter;
bool check(){
    for (int i = 1; i <= 3 ; ++i) {
        if(base[i] != 0){
            return true;
        }
    }
    return false;
}
void game(int time){

    int temp[9];
    int outcount = 0;

    for (int i = 0; i < 9; ++i) {
        temp[i] = bat[time][rtemp[i]];
    }
    while(1){
        if(temp[iter] == 0){
            outcount++;
        }
        else{
            if(check()){
                if(temp[iter] == 4) cnt++;
                for (int i = 3; i >= 1; i--) {
                    if(base[i]  == 0) continue;
                    int idx = i;
                    idx += temp[iter];

                    if(idx >=4) {
                        base[i] = 0;
                        cnt++;
                    }
                    else{
                        base[idx] = 1;
                        base[i] = 0;
                    }
                }
                base[temp[iter]] = 1;
            }
            else{
                if(temp[iter] == 4) {cnt++;}

                else {
                    int idx = temp[iter];
                    //printf("%d ",idx);
                    base[idx] = 1;

                }

            }
        }
        n=k;
        iter++;
        if(iter == 9) iter = 0;

        if(outcount == 3){
            //printf("%d\n",n);
            memset(base, 0, sizeof(base));
            break;
        }
    }
}
void DFS(int depth){

    if(depth == 9){
        //printf("%d\n",n);
        cnt=0;
        rtemp[3] = 0;
        iter=0;
        for (int c = 0; c < n; ++c) {
            //printf("%d %d ",c,n);
            game(c);

        }
        //printf("\n");
       // printf("%d\n",cnt);
        score = max(cnt,score);
        //printf("%d\n",score);
        return;
    }
    for (int i = 1; i < 9; ++i) {
        if(depth == 3) depth+=1;
        if(!visit[i]){
            visit[i] = 1;
            rtemp[depth] = i;
            DFS(depth+1);
            visit[i] = 0;
        }
    }

}
int main(){

    scanf("%d",&n);

    k = n;

    //printf("%d",n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d",&bat[i][j]);
        }
    }
    //printf("%d \n",n);
    DFS(0);
    printf("%d",score);
}