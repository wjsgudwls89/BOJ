//
// Created by 전형진 on 2020-02-24.
//
#include <stdio.h>
#include <algorithm>

using namespace std;

struct INFO{
    int link = -1;
};

INFO info[31][11];
int visit[31][11];
int N,M,H;
int ans = 9999;
bool flag = false;
int a, b;
bool check(int idx){
    int end  = idx;
    for (int i = 1; i <=H ; ++i) {
        if(info[i][idx].link != -1) {
            idx = info[i][idx].link;
        }

    }

    if(end != idx){
        return false;
    }
    return true;
}
void DFS(int depth,int c,int hst){
    if(depth == c){
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {

            if(check(i)){
                cnt++;
            }
            else {
                return;
            }
        }

        if(cnt == N) {
            ans = min(ans, c);
            //printf("ans: %d\n", ans);

            return;
        }
        else {
            return;
        }
    }

    for (int i = hst; i <= H; ++i) {
        for (int j = 1; j < N; ++j) {
            if(!visit[i][j] && info[i][j].link == -1 && info[i][j+1].link == -1){
                visit[i][j] = 1;
                visit[i][j+1] = 1;
                info[i][j].link = j+1;
                info[i][j+1].link = j;
                DFS(depth+1,c,i);
                visit[i][j] = 0;
                visit[i][j+1] = 0;//
// Created by 전형진 on 2020-02-24.
//
#include <stdio.h>
#include <algorithm>

                using namespace std;

                struct INFO{
                    int link = -1;
                };

                INFO info[31][11];
                int visit[31][11];
                int N,M,H;
                int ans = 9999;
                bool flag = false;
                int a, b;
                bool check(int idx){
                    int end  = idx;
                    for (int i = 1; i <=H ; ++i) {
                        if(info[i][idx].link != -1) {
                            idx = info[i][idx].link;
                        }

                    }

                    if(end != idx){
                        return false;
                    }
                    return true;
                }
                void DFS(int depth,int c,int hst){
                    if(depth == c){
                        int cnt = 0;
                        for (int i = 1; i <= N; ++i) {

                            if(check(i)){
                                cnt++;
                            }
                            else {
                                return;
                            }
                        }

                        if(cnt == N) {
                            ans = min(ans, c);
                            //printf("ans: %d\n", ans);

                            return;
                        }
                        else {
                            return;
                        }
                    }

                    for (int i = hst; i <= H; ++i) {
                        for (int j = 1; j < N; ++j) {
                            if(!visit[i][j] && info[i][j].link == -1 && info[i][j+1].link == -1){
                                visit[i][j] = 1;
                                visit[i][j+1] = 1;
                                info[i][j].link = j+1;
                                info[i][j+1].link = j;
                                DFS(depth+1,c,i);
                                visit[i][j] = 0;
                                visit[i][j+1] = 0;
                                info[i][j].link = -1;
                                info[i][j+1].link = -1;
                            }
                        }
                    }
                }
                int main(){

                    scanf("%d %d %d",&N,&M,&H);

                    for (int i = 0; i < M; ++i) {
                        scanf("%d %d",&a,&b);
                        info[a][b].link = b+1;
                        info[a][b+1].link = b;
                        visit[a][b] = 1;
                        visit[a][b+1] = 1;

                    }
                    for (int i = 0; i <=3; ++i) {
                        DFS(0,i,1);

                    }

                    if(ans == 9999){
                        printf("-1");
                    }
                    else {
                        printf("%d", ans);
                    }
                }
                info[i][j].link = -1;
                info[i][j+1].link = -1;
            }
        }
    }
}
int main(){

    scanf("%d %d %d",&N,&M,&H);

    for (int i = 0; i < M; ++i) {
        scanf("%d %d",&a,&b);
        info[a][b].link = b+1;
        info[a][b+1].link = b;
        visit[a][b] = 1;
        visit[a][b+1] = 1;

    }
    for (int i = 0; i <=3; ++i) {
        DFS(0,i,1);

    }

    if(ans == 9999){
        printf("-1");
    }
    else {
        printf("%d", ans);
    }
}