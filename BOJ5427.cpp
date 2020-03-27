////
//// Created by 전형진 on 2020-03-27.
////
//#include <stdio.h>
//#include <queue>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//struct POS{
//    int y;
//    int x;
//    char c;
//};
//int test;
//
//char map[1001][1001];
//int visit[1001][1001];
//int tvisit[1001][1001];
//int dx[] = {1,0,-1,0};
//int dy[] = {0,1,0,-1};
//
//int w,h;
//queue<POS> q;
//queue<POS> temp;
//queue<POS> fq;
//
//int RBFS(){
//    int cnt = 0;
//    while(!q.empty()) {
//        int qs = q.size();
//        while (qs--) {
//            int y = q.front().y;
//            int x = q.front().x;
//            q.pop();
//
//            if ((y == 0 || y == h - 1 || x == w - 1 || x == 0)) {
//                return cnt;
//            }
//
//            for (int i = 0; i < 4; ++i) {
//                int ny = y + dy[i];
//                int nx = x + dx[i];
//
//                if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
//                    if (tvisit[ny][nx] == 0  && map[ny][nx] == '.') {
//                        if(visit[ny][nx])
//                        q.push({ny, nx});
//                        tvisit[ny][nx] = tvisit[y][x] +1;
//                    }
//                }
//            }
//        }
//        cnt++;
//    }
//    return -1;
//}
//void BFS(){
//    while(!fq.empty()) {
//
//            int y = fq.front().y;
//            int x = fq.front().x;
//            char c = fq.front().c;
//            fq.pop();
//            for (int i = 0; i < 4; ++i) {
//                int ny = y + dy[i];
//                int nx = x + dx[i];
//
//                if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
//                    if (visit[ny][nx] == 0 && map[ny][nx] != '#') {
//                        fq.push({ny,nx});
//                        visit[ny][nx] = visit[y][x] + 1 ;
//                        }
//                    }
//                }
//            }
//}
//int main(){
//    scanf("%d",&test);
//    for (int t = 0; t < test; ++t) {
//
//        scanf("%d %d",&w,&h);
//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                cin>>map[i][j];
//
//                if(map[i][j] == '*'){
//                    fq.push({i,j,'*'});
//                    visit[i][j] = 1;
//                }
//                else if(map[i][j] == '#'){
//                    visit[i][j] = 1;
//                }
//                else if(map[i][j] == '@'){
//                    q.push({i,j,'@'});
//                    //visit[i][j] = 1;
//                }
//
//            }
//        }
//        BFS();
//        int ans = RBFS();
//
//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                printf("%d",visit[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//
//        if(ans == -1){
//            printf("IMPOSSIBLE\n");
//        }
//        else{
//            printf("%d\n",ans+1);
//        }
//        memset(visit,0, sizeof(visit));
//        memset(tvisit,0, sizeof(visit));
//        q=temp;
//        fq=temp;
//        //memset(map,'0', sizeof(map));
//    }
//}

//
// Created by 전형진 on 2020-03-27.
//
#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

struct POS{
    int y;
    int x;
    char c;
};
int test;

char map[1001][1001];
int visit[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int w,h;
queue<POS> q;
queue<POS> temp;
queue<POS> fq;

int BFS(){
    int cnt = 1;

    while(!fq.empty() || !q.empty()) {
        int fqs = fq.size();
        int qs = q.size();
        while(fqs--){
        int fy = fq.front().y;
        int fx = fq.front().x;

        fq.pop();

        for (int i = 0; i < 4; ++i) {
            int fny = fy + dy[i];
            int fnx = fx + dx[i];

            if (fnx >= 0 && fny >= 0 && fnx < w && fny < h) {
                if (visit[fny][fnx] == 0 && map[fny][fnx] != '#') {
                    fq.push({fny, fnx});
                    visit[fny][fnx] = 1;
                }
            }
        }
    }
                while (qs--) {
                    int y = q.front().y;
                    int x = q.front().x;
                    q.pop();
                    if ((y == 0 ||y == h - 1 || x == w - 1 || x == 0)) {
                        return cnt;
                    }
                    for (int i = 0; i < 4; ++i) {

                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
                            if (visit[ny][nx] == 0 && map[ny][nx] == '.') {
                                q.push({ny, nx});
                                visit[ny][nx] = 1;
                            }
                        }
                    }
            }
                cnt++;
    }
    return -1;
}
int main(){
    scanf("%d",&test);


    for (int t = 0; t < test; ++t) {


        scanf("%d %d",&w,&h);

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin>>map[i][j];

                if(map[i][j] == '*'){
                    fq.push({i,j,'*'});
                    visit[i][j] = 1;
                }
                else if(map[i][j] == '#'){
                    visit[i][j] = 1;
                }
                else if(map[i][j] == '@'){
                    q.push({i,j,'@'});
                    visit[i][j] = 1;
                }

            }
        }
        int ans = BFS();
//////
//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                printf("%d",visit[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");

        if(ans == -1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",ans);
        }
        q=temp;
        fq=temp;
        memset(visit,0, sizeof(visit));
        //memset(map,'0', sizeof(map));
    }
}