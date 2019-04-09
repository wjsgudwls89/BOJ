////
//// Created by 전형진 on 2019-04-08.
////
//
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//int arr[6];
//int lotto[14];
//int n;
//void dfs(int x,int y){
//    if(x==6) {
//        for(int i = 0; i < 6; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//        return;
//    }
//    for(int i=y;i<n;i++){
//        arr[x] = lotto[i];
//        dfs(x+1,i+1);
//    }
//}
//int main(){
//    while (1){
//        scanf("%d",&n);
//        if(n==0)
//            break;
//        for(int i=0;i<n;i++){
//            scanf("%d",&lotto[i]);
//        }
//
//        dfs(0,0);
//    }
//}