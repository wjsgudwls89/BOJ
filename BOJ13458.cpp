//
//  BOJ13458.cpp
//  BOJ
//
//  Created by 전형진 on 25/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>

long long arr[1000001];

long long N;

long long getMax(long long b,long long c){

    long long max = 0;
    for(int i = 0 ; i< N ; i++){
        arr[i] = arr[i] - b;
        max++;
        if(arr[i] > 0){
            if(arr[i]%c == 0)
                max += (arr[i]/c);
            else
                max += (arr[i]/c)+1;
        }
}
    return max;
}
int main(void){
    long long B,C;
    
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld",&arr[i]);
    }
    
    scanf("%lld %lld",&B,&C);
    printf("%lld",getMax(B,C));
}
