//
// Created by 전형진 on 2020-02-23.
//
#include <stdio.h>
#include <vector>

using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
struct SHARK{
    int r;
    int c;
    int s;
    int d;
    int z;
    int idx;
    bool death = true;
};
SHARK sh[10001];
int ans = 0;
int R,C,m;

vector<SHARK> v[101][101];

int r,c,s,d,z;
void kill(int i){
    for (int j = 1; j <= R; ++j) {
        if(v[j][i].size() != 0){
            sh[v[j][i][0].idx].death = false;
            ans += v[j][i][0].z;
            v[j][i].clear();
            break;
        }
    }

}
void move(){
    for (int i = 0; i < m; ++i) {
        if(!sh[i].death) continue;

        int y = sh[i].r;
        int x = sh[i].c;
        if(sh[i].s == 0){
            continue;
        }
        if(v[y][x].size()>1) {
            v[y][x].erase(v[y][x].begin() + 0);
        }
        else{
            v[y][x].pop_back();
        }

        for (int j = 0; j < sh[i].s; ++j) {
            y = y + dy[sh[i].d];
            x = x + dx[sh[i].d];

            if(x==1 && sh[i].d == 3){
                sh[i].d = 2;
            }
            else if(x == C && sh[i].d==2){
                sh[i].d = 3;
            }
            else if(y == 1 && sh[i].d ==0){
                sh[i].d = 1;
            }
            else if(y == R && sh[i].d==1){
                sh[i].d = 0;
            }
        }
        sh[i].r = y;
        sh[i].c = x;
        v[y][x].push_back(sh[i]);
//        printf("%d\n",i);
//        for (int i2 = 1; i2 <= R; ++i2) {
//            for (int j = 1; j <= C; ++j) {
//                printf("%d ",v[i2][j].size());
//            }
//            printf("\n");
//        }
//        printf("---------------------\n");

    }
    for (int i = 0; i < m; ++i) {
        if(!sh[i].death) continue;
        else if(v[sh[i].r][sh[i].c].size() > 1){
            SHARK temp;
            int max = 0;
            for (int j = 0; j < v[sh[i].r][sh[i].c].size(); ++j) {
                if(max<v[sh[i].r][sh[i].c][j].z){
                    max = v[sh[i].r][sh[i].c][j].z;
                    temp = v[sh[i].r][sh[i].c][j];
                }
                sh[v[sh[i].r][sh[i].c][j].idx].death = false;
            }
            //printf("%d %d\n",temp.r,temp.c);
            temp.death = true;
            sh[temp.idx].death = true;
            v[sh[i].r][sh[i].c].clear();
            v[sh[i].r][sh[i].c].push_back(temp);
        }
    }

}

int main(){

    scanf("%d %d %d",&R,&C,&m);

    for (int i = 0; i < m; ++i) {

        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);

        d-=1;
        if(r == 1 && d == 0) d= 1;
        else if(r == R && d == 1) d = 0;
        else if(c == 1 && d == 3) d = 2;
        else if(c == C && d == 2) d = 3;

        sh[i].r = r;
        sh[i].c = c;
        sh[i].s = s;
        sh[i].d = d;
        sh[i].z = z;
        sh[i].idx = i;

        v[r][c].push_back(sh[i]);
    }
    for (int i = 0; i < m; ++i) {
        if(sh[i].d<2){
            sh[i].s = sh[i].s%((R-1)*2);
        }
        else{
            sh[i].s = sh[i].s%((C-1)*2);
        }
    }

    for (int i = 1; i <= C; ++i) {
        kill(i);
        move();

    }
    printf("%d",ans);
}