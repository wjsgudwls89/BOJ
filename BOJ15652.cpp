////
//// Created by 전형진 on 2020-01-23.
////
//#include <stdio.h>
//int n,m;
//int arr[8];
//int visit[8][8];
//void dfs(int start,int depth)
//{
//    if(depth == m){
//        for (int i = 0; i < m; ++i) {
//            printf("%d ",arr[i]+1);
//        }
//        printf("\n");
//        return;
//    }
//    for (int i = start; i < n; ++i) {
//            arr[depth] = i;
//            dfs(i, depth + 1);
//    }
//}
//int main(){
//    scanf("%d %d",&n,&m);
//    dfs(0,0);
//
//}