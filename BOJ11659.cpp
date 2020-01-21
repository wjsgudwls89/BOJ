//
// Created by 전형진 on 2020-01-21.
//
#include <stdio.h>
int n,m;
int a,b;
int arr[100001];
int sum[100001];
int subSetSum(int a,int b){
    return sum[b] - sum[a-1];
}
void getSum(){
    sum[0] = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + arr[i];

    }
}
int main(){
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&arr[i]);
    }
    getSum();
    for (int j = 0; j < m; ++j) {
        scanf("%d %d",&a,&b);
        printf("%d\n",subSetSum(a,b));
    }

}