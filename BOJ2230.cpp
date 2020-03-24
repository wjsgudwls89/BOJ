//
// Created by 전형진 on 2020-03-24.
//
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int arr[100000];

int n,m;
int mins;
int main(){
    int start=0,end=0;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int temp = arr[start] - arr[end];
    sort(arr,arr+n);
    mins = 2000000000;


    while(start<= end && end < n){
        if(temp > m){
            if(mins>temp){
                mins = temp;
            }
            start++;
            if(start>end && start<n){
                end = start;
            }
            temp = abs(arr[end] - arr[start]);
        }
        else if(temp < m){
            end++;
            temp = abs(arr[end] - arr[start]);
        }
        else if(temp == m) {
            mins  = temp;
            break;
        }
    }
    printf("%d",mins);
}