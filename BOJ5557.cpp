//
// Created by 전형진 on 2020-02-10.
//
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
int n;
int visit[101];

int arr[101];

long dp[101][21];


int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dp[0][arr[0]]++;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 0; j <= 20 ; ++j) {
            if(dp[i-1][j]){
                if(j+arr[i]<=20) dp[i][j+arr[i]]+=dp[i-1][j];

                if(j-arr[i]>=0)  dp[i][j-arr[i]]+=dp[i-1][j];
            }
        }
    }

    cout<<dp[n-2][arr[n-1]];


}