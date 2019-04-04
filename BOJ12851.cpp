////
//// Created by 전형진 on 2019-04-02.
////
//
////
//// Created by 전형진 on 2019-04-02.
////
//
//#include <stdio.h>
//#include <queue>
//#include <vector>
//
//int arr[100001];
//bool c[100001];
//using namespace std;
//int n,k,cnt;
//int mins = 999999;
//
//
//void bfs(int n, int k){
//    int counts = 0;
//    int dx[] = {1,-1};
//    queue<int> q;
//
//    q.push(n);
//
//
//    while(!q.empty()){
//        int qs=q.size();
//        while(qs--) {
//            int x = q.front();
//            c[x] = true;
//            q.pop();
//            if (x == k){
//                if(counts <=mins){
//                    mins = counts;
//                    cnt++;
//                }
//                else
//                    return;
//
//            }
//            int nx;
//            for (int i = 0; i < 3; i++) {
//                if (i < 2) {
//                    nx = x + dx[i];
//                }
//                else {
//                    nx = 2 * x;
//                }
//                if(nx >= 0 && nx<=100000) {
//                    if (!c[nx]) {
//                        q.push(nx);
//                    }
//                }
//            }
//        }
//        counts++;
//
//    }
//}
//int main(){
//    scanf("%d %d",&n,&k);
//    arr[n] = n;
//    arr[k] = k;
//    bfs(arr[n],arr[k]);
//    printf("%d\n",mins);
//    printf("%d",cnt);
//}