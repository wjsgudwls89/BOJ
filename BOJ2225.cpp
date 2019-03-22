//
//  BOJ2225.cpp
//  BOJ
//
//  Created by 전형진 on 22/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>

int arr[200][200];

int dp(int N,int K){
    
    if(arr[N][K] != 0)
        return arr[N][K];
    
    return arr[N][K] = (dp(N-1,K) + dp(N,K-1))%1000000000;
}

int main(){
    int N;
    int K;
    
    scanf("%d %d",&N,&K);
    
    for(int i = 0 ; i< 200; i++){
        arr[i][0] = 1;
        arr[0][i] = i+1;
    }
    int a = dp(N-1,K-1);
    printf("%d",a);
    
    return 0;
}
