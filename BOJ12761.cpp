//
//  BOJ12761.cpp
//  BOJ
//
//  Created by 전형진 on 19/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

bool c[100001];
int counts = 0;

void bfs(int a,int b ,int N,int m){
    int way[8] = {1,-1,a,b,-a,-b,a,b};
    queue<int> q;
    q.push(N);
    c[N] = true;

    

    while(!q.empty()){
        int sz = q.size();
    while(sz--){
        int x = q.front();
        q.pop();
                    if(x == m){
            printf("%d",counts);
            return ;
        }
        int k;
        
        for(int i = 0 ; i<8 ; i++){
            if(i >= 6){
                k = x * way[i];
            }
            else{
                k = x + way[i];
            }
            if(k >= 0 && k <= 100000){
            if(!c[k]){
                q.push(k);
                c[k] = true;
                }
            }
        }
        }
        counts++;
    }
}
int main(){
    
    int M;
    int N;
    int A;
    int B;
    
    
    scanf("%d %d %d %d",&A,&B,&N,&M);
    bfs(A,B,N,M);
}
