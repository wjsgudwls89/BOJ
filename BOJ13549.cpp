////
//// Created by 전형진 on 2019-04-02.
////
//
//#include <stdio.h>
//#include <queue>
//#include <vector>
//
//int arr[100001];
//int c[100001];
//using namespace std;
//int n,k;
//
//void bfs() {
//    int dx[] = {1, -1};
//    queue<int> q;
//    q.push(n);
//    c[n] = 1;
//
//    int nx;
//    while (!q.empty()) {
//            int x = q.front();
//            q.pop();
//            for (int i = 0; i < 2; i++) {
//                nx = x + dx[i];
//                if (nx < 0 || nx >100000) continue;
//                    if (c[nx] == 0 || c[nx] > c[x] + 1) {
//                        q.push(nx);
//                        c[nx] = c[x] + 1;
//                    }
//                }
//
//            nx = 2 * x;
//            if (nx < 0 || nx > 100000) continue;
//                if (c[nx] == 0 || c[nx] > c[x]) {
//                    q.push(nx);
//                    c[nx] = c[x];
//                }
//
//        }
//    printf("%d",c[k]-1);
//}
//
//int main(){
//
//    scanf("%d %d",&n,&k);
//    bfs();
//}