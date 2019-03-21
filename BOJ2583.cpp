//
//  BOJ2583.cpp
//  BOJ
//
//  Created by 전형진 on 21/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//


#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

    int M,N,K;
int c[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<int> s;
struct node{
    int startx;
    int starty;
    int endx;
    int endy;
};
int cnt = 0;
int space[101][101];
node area[100];

void bfs(int x,int y){
    int sum = 0;
    queue<int> xq;
    queue<int> yq;
    space[x][y] = 2;
    xq.push(x);
    yq.push(y);

    
    while (!xq.empty()) {
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();
        sum++;
        for(int j =0 ; j<4 ; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx>=0 && nx < M && ny >=0 && ny < N && space[nx][ny] == 0)
            {
            space[nx][ny] = 2;
            xq.push(nx);
            yq.push(ny);
            }
        }
    }
    s.push_back(sum);
    cnt++;
}

int main(){

    
    scanf("%d %d %d", &M,&N,&K);
    for (int i= 0; i<K; i++) {
        scanf("%d %d %d %d",&area[i].startx,&area[i].starty,&area[i].endx,&area[i].endy);
    }
    
    for (int i = 0; i<M ; i++) {
        for (int j = 0; j<N; j++) {
            space[i][j]=0;
        }
    }
    for(int i  = 0 ; i< K ; i++){
    for (int k = area[i].starty; k < area[i].endy; k++) {
        for (int j = area[i].startx; j<area[i].endx; j++) {
            space[k][j]=1;
        }
    }
    }
    
    for (int i = 0; i<M ; i++) {
        for (int j = 0; j<N; j++) {
            if(space[i][j] == 0){
                bfs(i,j);
            }
        }
    }
    sort(s.begin(),s.end());
    printf("%d\n",cnt);
    for (int i = 0
         ;i<s.size();i++ ) {
        printf("%d ",s[i]);
    }
    
}

