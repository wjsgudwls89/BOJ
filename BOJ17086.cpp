////
//// Created by 전형진 on 2019-05-14.
////
//#include <stdio.h>
//#include <queue>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//struct SHARK{
//    int y;
//    int x;
//};
//int map[51][51];
//int dx[] = {1,1,1,-1,-1,-1,0,0};
//int dy[] = {0,1,-1,0,-1,1,1,-1};
//int n,m;
//int idx = 0;
//queue<SHARK> q;
//
//void bfs() {
//        while (!q.empty()) {
//                int y = q.front().y;
//                int x = q.front().x;
//                q.pop();
//                for (int i = 0; i < 8; ++i) {
//                    int nx = x + dx[i];
//                    int ny = y + dy[i];
//                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 0) {
//                        q.push({ny,nx});
//                        map[ny][nx] = map[y][x]+1;
//                    }
//                }
//        }
//}
//int main(){
//    scanf("%d %d",&n,&m);
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0 ; j < m; ++j) {
//            scanf("%d",&map[i][j]);
//            if(map[i][j] == 1) {
//                q.push({i,j});
//            }
//        }
//    }
//    bfs();
//    int ans = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0 ; j < m; ++j) {
//            if(map[i][j] > ans)
//                ans = map[i][j];
//        }
//
//    }
//    printf("%d",ans-1);
//}
