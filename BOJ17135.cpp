//
// Created by 전형진 on 2019-05-08.
//
#include <stdio.h>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct ARC{
    int dis;
    int y=0;
    int x=0;
    int idx;
};
bool cmp(const ARC &p1, const ARC &p2){
    if(p1.dis<p2.dis) {
        return true;
    }
    else if(p1.dis == p2. dis) {
        return p1.x < p2.x;
    }
    else return false;

}
ARC arc[16];
vector <ARC> a;
vector <ARC> e;
vector <ARC> temp;
vector <ARC> die[3];

int real[16][16];
int map[16][16];
bool check[15];
int n,m,d;
int ans;
void kill(int dis) {
    int rmax = 0;
    for (int i = 0; i < m; ++i) {
        if (check[i]) {
            a.push_back(arc[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < temp.size(); ++j) {
            if (abs(a[0].y - temp[j].y) + abs(a[0].x - temp[j].x) <= dis) {
                int tdis = abs(a[0].y - temp[j].y) + abs(a[0].x - temp[j].x);
                die[0].push_back({tdis, temp[j].y, temp[j].x, j});
            }
            if (abs(a[1].y - temp[j].y) + abs(a[1].x - temp[j].x) <= dis) {
                int tdis = abs(a[1].y - temp[j].y) + abs(a[1].x - temp[j].x);
                die[1].push_back({tdis, temp[j].y, temp[j].x, j});
            }
            if (abs(a[2].y - temp[j].y) + abs(a[2].x - temp[j].x) <= dis) {
                int tdis = abs(a[2].y - temp[j].y) + abs(a[2].x - temp[j].x);
                die[2].push_back({tdis, temp[j].y, temp[j].x, j});
            }
        }
        for (int l = 0; l < 3; ++l) {
            if (die[l].size() > 1) {
                sort(die[l].begin(), die[l].end(), cmp);
                if (temp[die[l][0].idx].y == 9999) {
                    rmax--;
                } else
                    temp[die[l][0].idx].y = 9999;
                rmax++;
                die[l].clear();
            } else if (die[l].size() == 1) {
                if (temp[die[l][0].idx].y == 9999) {
                    rmax--;
                } else
                    temp[die[l][0].idx].y = 9999;
                rmax++;
                die[l].clear();
            }
        }
        a[0].y--;
        a[1].y--;
        a[2].y--;

        for (int k = 0; k < temp.size(); ++k) {
            if (temp[k].y == a[0].y) {
                temp[k].y = 9999;
            }
        }
    }
    a.clear();
    ans = max(ans, rmax);
}
void dfs(int start,int cnt){
    if(cnt == 3) {
        temp  = e;
        kill(d);
        return;
    }
    else
        {
        for (int i = start; i < m; i++) {
            if (check[i] == 0) {
                check[i] = 1;
                dfs(i+1, cnt + 1);
                check[i] = 0;

            }
        }
    }

}
int main(){
    scanf("%d %d %d",&n,&m,&d);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&real[i][j]);
            if(real[i][j] == 1) {
                e.push_back({0,i,j});
            }
        }
    }
        for (int j = 0; j <m ; ++j) {
            arc[j].y=n;
            arc[j].x=j;
        }
        dfs(0,0);
        printf("%d",ans);
}