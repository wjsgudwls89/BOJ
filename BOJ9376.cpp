//
// Created by 전형진 on 2020-02-25.
//
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>


using namespace std;

//char map[100][100];
//
//int visit[100][100];
//int rvisit[100][100];

//int h,w;
//int ans = 9999;
//int tans = 9999;
//int ay[2];
//int ax[2];
//void NDFS(int y,int x,int cnt){
//    if(cnt>ans) return;
//    if(y == h-1 || x == w-1 || x == 0 || y == 0){
//
//        //printf("%d\n",cnt);
//        ans = min(cnt,ans);
//        return;
//
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        int nx = x+dx[i];
//        int ny = y+dy[i];
//
//        if(nx>=0 && ny >=0 && nx< w && ny < h){
//            if(rvisit[ny][nx] == 0){
//                if(map[ny][nx] == '.' || map[ny][nx] == '$'){
//                    rvisit[ny][nx] = 1;
//                    NDFS(ny,nx,cnt);
//                    rvisit[ny][nx] = 0;
//                }
//                else if(map[ny][nx] == '#'){
//                    rvisit[ny][nx] = 1;
//                    map[ny][nx] = '.';
//                    cnt++;
//                    NDFS(ny,nx,cnt);
//                    map[ny][nx] = '#';
//                    rvisit[ny][nx] = 0;
//                    cnt--;
//                }
//            }
//
//        }
//    }
//}
//void DFS(int y,int x,int cnt){
//
//    if(y == h-1 || x == w-1 || x == 0 || y == 0){
////        for (int i = 0; i < h; ++i) {
////            for (int j = 0; j < w; ++j) {
////                printf("%d ",visit[i][j]);
////            }
////            printf("\n");
////        }
////        printf("\n");
//       //printf("%d\n",cnt);
//
//        //memcpy(visit,rvisit, sizeof(visit));
//        NDFS(ay[1],ax[1],cnt);
//        return;
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        int nx = x+dx[i];
//        int ny = y+dy[i];
//
//        if(nx>=0 && ny >=0 && nx< w && ny < h){
//            if(visit[ny][nx] == 0){
//                if(map[ny][nx] == '.' || map[ny][nx] == '$'){
//                    visit[ny][nx] = 1;
//                    DFS(ny,nx,cnt);
//                    visit[ny][nx] = 0;
//                }
//                else if(map[ny][nx] == '#'){
//                    visit[ny][nx] = 1;
//                    map[ny][nx] = '.';
//                    cnt++;
//                    DFS(ny,nx,cnt);
//                    visit[ny][nx] = 0;
//                    map[ny][nx] = '#';
//                    cnt--;
//                }
//            }
//
//        }
//    }
//}
//int main(){
//    int tc;
//    scanf("%d",&tc);
//    for (int test = 0; test < tc; ++test) {
//
//        memset(visit,0, sizeof(visit));
//        memset(rvisit,0, sizeof(rvisit));
//        scanf("%d %d", &h, &w);
//        int idx = 0;
//        ans = 9999;
//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                cin >> map[i][j];
//                if (map[i][j] == '*') {
//                    visit[i][j] = 1;
//                    rvisit[i][j] = 1;
//                }
//                if (map[i][j] == '$') {
//                    ay[idx] = i;
//                    ax[idx] = j;
//                    idx++;
//                }
//            }
//        }
//        DFS(ay[0], ax[0], 0);
//        printf("%d\n", ans);
//    }
//}
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int h,w;
struct MAN{
    int y;
    int x;
};
MAN man[3];
char map[102][102];
int dist[102][102][3];

void BFS() {
    for (int i = 0; i < 3; ++i) {


        deque<MAN> q;
        int sy = man[i].y;
        int sx = man[i].x;
        q.push_back({sy,sx});
        dist[man[i].y][man[i].x][i] = 0;


        while (!q.empty()) {

            int x = q.front().x;
            int y = q.front().y;
            //printf("%d",q.size());
            q.pop_front();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx > w + 1 || ny > h + 1) continue;
                if (dist[ny][nx][i] >= 0 || map[ny][nx] == '*') continue;
                if (map[ny][nx] == '.') {
                    dist[ny][nx][i] = dist[y][x][i];
                    q.push_front({ny, nx});
                } else if (map[ny][nx] == '#') {
                    dist[ny][nx][i] = dist[y][x][i] + 1;
                    q.push_back({ny, nx});
                }
            }
        }
    }
}
int main(){
    int tc;
    scanf("%d",&tc);
    for (int l = 0; l < tc; ++l)


    {
        memset(dist, -1, sizeof(dist));
        scanf("%d %d", &h, &w);
        int idx = 1;

        for (int i = 0; i < h + 2; ++i) {
            for (int j = 0; j < w + 2; ++j) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
                    map[i][j] = '.';
                } else {
                    cin >> map[i][j];
                }
                if (map[i][j] == '$') {
                    map[i][j] = '.';
                    man[idx].y = i;
                    man[idx].x = j;
                    idx++;
                }
            }
        }

        man[0].y = 0;
        man[0].x = 0;

        BFS();

        int ans = 9999;
        for (int i = 0; i < h + 2; ++i) {
            for (int j = 0; j < w + 2; ++j) {
                if (map[i][j] == '*') continue;
                int k = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
                if (map[i][j] == '#') {
                    k -= 2;
                }
                if (ans > k)ans = k;
            }
        }

        printf("%d\n", ans);
    }
}