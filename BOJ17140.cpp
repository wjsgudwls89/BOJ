//
// Created by 전형진 on 2019-10-14.
//
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int arr[102][102];
int mem[1020];
int r, c, k;

int rowcount = 3;
int colcount = 3;
int gettime = 0;
int ans = 0;
bool flag= false;

void sol() {
    while (1) {
        vector<int> size;
        if (gettime > 100) {
            flag = true;
            gettime = -1;
            ans = gettime;
            break;
        }
        if (arr[r - 1][c - 1] == k) {
            ans = gettime;
            break;
        } else {
            if (colcount >= rowcount) {
                for (int i = 0; i < colcount; ++i) {
                    vector<pair<int, int>> v;
                    memset(mem, 0, sizeof(mem));
                    for (int j = 0; j < rowcount; ++j) {
                        mem[arr[i][j]]++;
                    }
                    for (int j = 1; j < 101; ++j) {
                        if (mem[j] == 0)
                            continue;
                        v.push_back(make_pair(mem[j], j));
                    }
                    sort(v.begin(), v.end());
                    for (int row = 0; row < rowcount; row++) {
                        arr[i][row] = 0;
                    }
                    int idx = 0;
                    for (int row = 0; row < v.size(); ++row) {
                        arr[i][idx++] = v[row].second;
                        arr[i][idx++] = v[row].first;
                    }
                    size.push_back(idx);
                }
                sort(size.begin(), size.end());
                rowcount = size.back();
                gettime++;
            } else {
                for (int i = 0; i < rowcount; ++i) {
                    memset(mem, 0, sizeof(mem));
                    vector<pair<int, int>> v;
                    for (int j = 0; j < colcount; ++j) {
                        mem[arr[j][i]]++;
                    }
                    for (int j = 1; j < 101; ++j) {
                        if (mem[j] == 0)
                            continue;
                        v.push_back(make_pair(mem[j], j));
                    }
                    sort(v.begin(), v.end());
                    for (int j = 0; j < colcount; ++j) {
                        arr[j][i] = 0;
                    }
                    int idx = 0;
                    for (int j = 0; j < v.size(); ++j) {
                        arr[idx++][i] = v[j].second;
                        arr[idx++][i] = v[j].first;
                    }
                    size.push_back(idx);
                }
                sort(size.begin(), size.end());
                colcount = size.back();
                gettime++;
            }

        }
    }
}
int main(){

    scanf("%d %d %d",&r,&c,&k);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    sol();
    printf("%d",ans);
}