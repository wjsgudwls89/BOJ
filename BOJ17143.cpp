//
// Created by 전형진 on 2019-05-07.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int y,x,n;
deque<int> map[101][101];
vector<int> sum;


struct SHARK{

    int r;
    int c;
    int s;
    int d;
    int z;
    bool state = false;
};
SHARK sh[10001];

bool cmp(int ax,int ay){
    if(sh[ax].z<sh[ay].z)
        return false;
    else
        return true;
}

void kill(int k) {
    for (int i = 1; i <= y; ++i) {
        if (!map[i][k].empty()) {
            sum.push_back(map[i][k][0]);
            //printf("%d",sh[map[i][k][0]].z);
            sh[map[i][k][0]].state = false;
            map[i][k].pop_back();
            break;
        }
    }
}
void move() {
    for (int i = 1; i <= n; i++){
        if (sh[i].state) {
            int temp = sh[i].s;
            if(!map[sh[i].r][sh[i].c].empty()) {
                map[sh[i].r][sh[i].c].pop_front();
            }
            while (temp--) {
                if (sh[i].d == 1) {
                    if (sh[i].r == 1) {
                        sh[i].d = 2;
                        if(temp >= 0)
                            sh[i].r++;
                    }
                    else {
                        sh[i].r--;
                        if(sh[i].r == 1)
                            sh[i].d = 2;
                    }
                }
                else if (sh[i].d == 2) {
                    if (sh[i].r == y) {
                        sh[i].d = 1;
                        if(temp >= 0)
                            sh[i].r--;
                    }
                    else {
                        sh[i].r++;
                        if(sh[i].r == y)
                            sh[i].d=1;
                    }
                }
                else if (sh[i].d == 3) {
                    if (sh[i].c == x) {
                        sh[i].d = 4;
                        if(temp >= 0)
                            sh[i].c--;
                    }
                    else {
                        sh[i].c++;
                        if(sh[i].c == x)
                            sh[i].d = 4;
                    }
                }
                else if (sh[i].d == 4) {
                    if (sh[i].c == 1) {
                        sh[i].d = 3;
                        if(temp >= 0)
                            sh[i].c++;
                    }
                    else {
                        sh[i].c--;
                        if(sh[i].c ==1)
                            sh[i].d=3;
                    }
                }
            }
            map[sh[i].r][sh[i].c].push_back(i);
        }
    }
}
void dup() {
    for (int i = 1; i <= n; i++) {
        if (map[sh[i].r][sh[i].c].size() > 1) {
            sort(map[sh[i].r][sh[i].c].begin(),map[sh[i].r][sh[i].c].end(),cmp);
            for (int k = 0; k < map[sh[i].r][sh[i].c].size(); ++k) {
                sh[map[sh[i].r][sh[i].c][k]].state = false;
            }
            int temp = map[sh[i].r][sh[i].c][0];
            map[sh[i].r][sh[i].c].clear();
            sh[temp].state=true;
            map[sh[i].r][sh[i].c].push_back(temp);

        }
    }
}

int main(){

    scanf("%d %d %d",&y,&x,&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d %d",
                &sh[i].r,&sh[i].c,&sh[i].s,&sh[i].d,&sh[i].z);
                sh[i].state = true;
                map[sh[i].r][sh[i].c].push_front(i);
    }
    for (int i = 1; i <= x; ++i) {
        kill(i);
        move();
        dup();
    }
    int sol=0;
    for (int i = 0; i < sum.size(); ++i) {
       if(!sh[sum[i]].state)
        sol+=sh[sum[i]].z;
    }
   printf("%d",sol);
}
