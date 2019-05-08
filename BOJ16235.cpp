//
// Created by 전형진 on 2019-05-04.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <ctime>

using namespace std;

struct ATREE{
    int x;
    int y;
    int age;
};

vector<int> tree[11][11];

int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int land[11][11];
int n,m,K;
int A[11][11];
int x,y,z;
int tcnt = 0;
int springcnt = 0;
clock_t start, ends;
//vector<int> atree;
queue<ATREE> dtree;
void spring() {

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int sum = 0;
            vector<int> atree;
            if (!tree[i][j].empty()) {
                    sort(tree[i][j].begin(),tree[i][j].end());
                for (int k = 0; k < tree[i][j].size(); k++) {
                    //int age = tree[i][j][k];
                    if (tree[i][j][k] <= land[i][j]) {
                        land[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                        atree.push_back(tree[i][j][k]);
                    }
                    else
                        {
                        sum+=(tree[i][j][k])/2;
                    }
                }
                tree[i][j].clear();
                for(int l=0;l<atree.size();l++){
                    tree[i][j].push_back(atree[l]);
                }
                land[i][j] += sum;
            }
        }
    }
}
void autumn() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=n; ++j) {
            if (!tree[i][j].empty()) {
                for (int k = 0; k < tree[i][j].size(); ++k) {
                    if (tree[i][j][k] % 5 == 0) {
                        for (int l = 0; l < 8; ++l) {
                            int ny = i + dy[l];
                            int nx = j + dx[l];
                            if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                                tree[ny][nx].push_back(1);
                            }
                        }
                    }
                }
            }
        }
    }
}
void winter(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            land[i][j] += A[i][j];
        }
    }
}
void gettree() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt+=tree[i][j].size();
        }
    }
    ends = clock();
    printf("%lg", (long double)(ends - start) / CLOCKS_PER_SEC);
    printf("\n");
    printf("%d",cnt);
}
int main(){

    start = clock();
    scanf("%d %d %d",&n,&m,&K);


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            scanf("%d",&A[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&x,&y,&z);
        tree[x][y].push_back({z});
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            land[i][j] = 5;
        }
    }
    for(int year = 0 ; year<K;year++) {
        spring();
        //summer();
        autumn();
        winter();
    }
    gettree();
}