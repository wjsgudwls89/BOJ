//
// Created by 전형진 on 2020-03-24.
//
#include <stdio.h>

int arr[10001];

int cnt = 0;
int n, m;
int sum = 0;
int main(){
    int start = 0;
    int end = 0;
    scanf("%d %d",&n,&m);

    for (int i = 0; i <n ; ++i) {
        scanf("%d",&arr[i]);
    }
    sum = arr[0];
    while(start <= end && end < n){
        if(sum == m){
            cnt++;
            end++;
            sum+=arr[end];
        }
        else if(sum>m) {
            sum -= arr[start];
            start++;

            if (start > end && start < n) {
                end = start;
                sum = arr[start];
            }
        }
        else if(sum<m){
            end++;
            sum+=arr[end];
        }
    }
    printf("%d",cnt);
}