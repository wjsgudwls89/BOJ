////
//// Created by 전형진 on 2020-01-23.
////
////
//// Created by 전형진 on 2020-01-23.
////
////
//// Created by 전형진 on 2020-01-23.
////
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//int n,m;
//int arr[8];
//int ans[8];
//int visit[10001];
//void dfs(int start,int depth){
//    if(depth == m){
//        for (int i = 0; i < m; ++i) {
//            printf("%d ", ans[i]);
//        }
//        printf("\n");
//        return;
//    }
//    int before = 0;
//    for (int i = start; i < n; ++i) {
//        if(before != arr[i]) {
//            before = arr[i];
//            ans[depth] = arr[i];
//            dfs(i, depth + 1);
//        }
//
//    }
//}
//
//int main(){
//    scanf("%d %d",&n,&m);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d",&arr[i]);
//    }
//    sort(arr,arr+n);
//    dfs(0,0);
//}