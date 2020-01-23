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
//int visit[8];
//void dfs(int start,int depth){
//    if(depth == m){
//        for (int i = 0; i < m; ++i) {
//            printf("%d ", ans[i]);
//        }
//        printf("\n");
//        return;
//    }
//    for (int i = start; i < n; ++i) {
//        if(visit[i] == 0) {
//            ans[depth] = arr[i];
//            visit[i] = 1;
//            dfs(i + 1, depth + 1);
//            visit[i] = 0;
//
//        }
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