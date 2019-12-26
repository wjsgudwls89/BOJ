//
// Created by 전형진 on 2019-12-26.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

int n = 9;
string c;
int check[25] ={0};
int comp = (1<<26) -1;
int ans = 0;
int cnt = 0;
char str[25][100];

void powerset(int depth,int sum){
    if(depth == n){
        if(sum == comp)
            ans++;

        return;
    }
    else{
        powerset(depth+1,sum|check[depth]);
        powerset(depth+1,sum);
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        cin>>str[i];
            for (int j = 0; j < strlen(str[i]); ++j) {
                int k = str[i][j]-97;
                check[i] |=(1<<k);
        }
    }
    powerset(0,0);
    printf("%d",ans);
}
