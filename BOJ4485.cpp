////
//// Created by 전형진 on 2019-04-05.
////
//#include <stdio.h>
//#include <queue>
//#include <vector>
//using namespace std;
//
//vector<pair<int,int>> v;
//int cnt =0;
//int n;
//int cave[125][125];
//int dis[125][125];
//int mins=99999;
//int dx[]={0,1,0,-1};
//int dy[]={1,0,-1,0};
//
//void dijkstra(int y, int x){
//    dis[0][0] = cave[y][x];
//    queue<int> q;
//    queue<int> xq;
//    queue<int> yq;
//    q.push(dis[0][0]);
//    xq.push(x);
//    yq.push(y);
//    while(!q.empty()){
//        int curdis = q.front();
//        int x = xq.front();
//        int y = yq.front();
//        q.pop();xq.pop();yq.pop();
//        for(int i=0;i<4;i++){
//            int nx = x +dx[i];
//            int ny = y +dy[i];
//            if(nx>=0&&ny>=0&&ny<n&&nx<n){
//                if(dis[ny][nx] > curdis + cave[ny][nx]) {
//                    dis[ny][nx] = curdis + cave[ny][nx];
//                    xq.push(nx);
//                    yq.push(ny);
//                    q.push(dis[ny][nx]);
//                }
//            }
//        }
//    }
//    printf("Problem %d: %d\n",cnt+1,dis[n-1][n-1]);
//    cnt++;
//}
//int main(){
//    while(1) {
//        scanf("%d", &n);
//        if(n == 0)
//            break;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                scanf("%d", &cave[i][j]);
//                dis[i][j] = mins;
//            }
//        }
//        dijkstra(0,0);
//   }
//}