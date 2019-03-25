//
//  BOJ11403.cpp
//  BOJ
//
//  Created by 전형진 on 25/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int graph[101][101];
int check[101][101];
vector <int> a[100];

//find parent
void bfs(int start, int hang){
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < a[x].size();i++){
            int y = a[x][i];
            if(!check[hang][y]){
                q.push(y);
                check[hang][y] = true;
            }
        }
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0 ; i < N ; i ++){
        for(int j=0;j < N;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0 ; i < N ; i++){
        for(int j=0;j < N;j++){
            if(graph[i][j] != 0){
                a[i].push_back(j);
            }
        }
    }
    for (int i =0; i< N; i++) {
        bfs(i,i);
    }

    for(int i=0 ; i < N ; i++){
        for(int j=0;j < N;j++){
            printf("%d ",check[i][j]);
        }
        printf("\n");
    }
    return 0;
}
