//
// Created by 전형진 on 2020-02-09.
//
#include <stdio.h>
#include <algorithm>


using namespace std;
int n, k;
int arr[100001];
int tarr[100001];
int ans = -99999999;
void getans(int k){
    if(n == k){
        ans = tarr[n-1];
    }
    else {
        for (int i = k-1; i < n; ++i) {
            int temp = tarr[i] - tarr[i - k];
            ans = max(temp, ans);
        }
    }
}
int main(){
    scanf("%d %d",&n,&k);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        tarr[i] = sum;
    }

    getans(k);
    printf("%d",ans);
}