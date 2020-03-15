//
// Created by 전형진 on 2020-03-15.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int temp[11];
int cal[4];
int visit[11];
int n;
int num;
int sum;
int tsum;
int amax = -1000000001;
int amin = 1000000001;

vector<int> v;
vector<int> a;
int calc(int idx,int a,int b){
    if(idx == 1){
        return a+b;
    }
    if(idx == 2){
        return a-b;
    }
    if(idx == 3){
        return a*b;
    }
    if(idx == 4){
        return a/b;
    }
}


void DFS(int depth){
    if(depth == n-1){
        tsum = sum;
        for (int i = 0; i < n-1; ++i) {
            tsum = calc(temp[i],tsum,v[i+1]);
        }
        amax = max(tsum,amax);
        amin = min(tsum,amin);
        return;
    }
    for (int i = 0; i < a.size(); ++i) {
        if(visit[i] == 0) {
            visit[i] = 1;
            temp[depth] = a[i];
            DFS(depth + 1);
            visit[i] = 0;
        }
    }
}
int main(){
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
       scanf("%d",&num);
       if(i == 0)  sum = num;
       v.push_back(num);
    }
    for (int i = 0; i < 4; ++i) {
        scanf("%d",&cal[i]);
        for (int j = 0; j < cal[i]; ++j) {
            a.push_back(i+1);
        }
    }
    DFS(0);
    printf("%d\n%d\n",amax,amin);
}