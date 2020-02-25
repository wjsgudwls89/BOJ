//
// Created by 전형진 on 2020-02-25.
//

//
// Created by 전형진 on 2020-02-21.
//
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


int n,k;
int map[12][12];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

struct HORSE{
    int y;
    int x;
    int dir;
    int idx;
};
int a,b,c,d;
int ans = 0;
bool flag = false;
bool stat = true;
vector <HORSE> visit[12][12];
vector<HORSE> v;
void game(){
    while(stat) {
        ans++;


        if(ans>1000){ flag = true; return;}
        for (int i = 0; i < k; ++i) {
//            for (int a = 0; a < n; ++a) {
//                for (int b = 0; b < n; ++b) {
//                    printf("%d ",visit[a][b].size());
//
//                }
//                printf("\n");
//            }
//            printf("---------------------\n");
            int ny,nx;
            int y = v[i].y;
            int x = v[i].x;

            int dir = v[i].dir;
            int idx = v[i].idx;
            if(visit[y][x][0].idx != idx) continue;
            ny = y + dy[dir];
            nx = x + dx[dir];

            if(ny>=0 && nx>=0 && ny<n && nx<n) {
                if (map[ny][nx] == 0) {
                    int cnt = 0;

                        if(visit[y][x][0].idx != idx) continue;

                            for (int l = 0; l < visit[y][x].size(); ++l) {
                                v[visit[y][x][l].idx].y = ny;
                                v[visit[y][x][l].idx].x = nx;



                                visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                cnt++;
                                if(visit[ny][nx].size() == 4){
                                    return;
                                }
                            }


                    for (int j = 0; j < cnt; ++j) {
                        visit[y][x].pop_back();
                    }

                } else if (map[ny][nx] == 1) {
                    int cnt = 0;

                        if(visit[y][x][0].idx != idx)continue;

                            for (int l = visit[y][x].size() - 1; l >= 0; --l) {
                                v[visit[y][x][l].idx].y = ny;
                                v[visit[y][x][l].idx].x = nx;


                                visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                cnt++;
                                if(visit[ny][nx].size() == 4){
                                    return;
                                }


                    }

                    for (int j = 0; j < cnt; ++j) {
                        visit[y][x].pop_back();
                    }
                } else if (map[ny][nx] == 2) {

                    if (dir % 2 == 0) {
                        dir++;
                    } else {
                        dir--;
                    }
                    ny = y + dy[dir];
                    nx = x + dx[dir];
                    v[i].dir = dir;
                    if(nx>=0 && ny>=0 && nx<n && ny < n) {
                        if (map[ny][nx] == 0) {
                            int cnt = 0;

                                if(visit[y][x][0].idx != idx) continue;
                                    for (int l = 0; l < visit[y][x].size(); ++l) {
                                        v[visit[y][x][l].idx].y = ny;
                                        v[visit[y][x][l].idx].x = nx;


                                        visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                        cnt++;
                                        if(visit[ny][nx].size() == 4){
                                            return;
                                        }
                                    }




                            for (int j = 0; j < cnt; ++j) {
                                visit[y][x].pop_back();
                            }

                        } else if (map[ny][nx] == 1) {
                            int cnt = 0;

                                if(visit[y][x][0].idx != idx) continue;

                                    for (int l = visit[y][x].size() - 1; l >= 0; --l) {
                                        v[visit[y][x][l].idx].y = ny;
                                        v[visit[y][x][l].idx].x = nx;


                                        visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                        cnt++;
                                        if(visit[ny][nx].size() == 4){
                                            return;
                                        }


                            }

                            for (int j = 0; j < cnt; ++j) {
                                visit[y][x].pop_back();
                            }
                        } else if (map[ny][nx] == 2) {

                            v[i].dir = dir;
                        }
                    }
                    else if (ny >= n || nx >= n || ny < 0 || nx < 0) {

                        v[i].dir = dir;
                    }


                }
            }
            else if (ny >= n || nx >= n || ny < 0 || nx < 0) {
                if (dir % 2 == 0) {
                    dir++;
                } else {
                    dir--;
                }

                ny = y + dy[dir];
                nx = x + dx[dir];
                v[i].dir = dir;

                if (map[ny][nx] == 0) {

                    int cnt = 0;


                        if(visit[y][x][0].idx != idx) continue;
                            for (int l = 0; l < visit[y][x].size(); ++l) {

                                v[visit[y][x][l].idx].y = ny;
                                v[visit[y][x][l].idx].x = nx;


                                visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                cnt++;
                                if(visit[ny][nx].size() == 4){
                                    return;
                                }


                    }
                    for (int j = 0; j < cnt; ++j) {
                        visit[y][x].pop_back();
                    }

                } else if (map[ny][nx] == 1) {
                    int cnt = 0;

                        if(visit[y][x][0].idx != idx) continue;
                            for (int l = visit[y][x].size() - 1; l >= 0; --l) {
                                v[visit[y][x][l].idx].y = ny;
                                v[visit[y][x][l].idx].x = nx;


                                visit[ny][nx].push_back(v[visit[y][x][l].idx]);
                                cnt++;
                                if(visit[ny][nx].size() == 4){
                                    return;
                                }

                        }
                        for (int j = 0; j < cnt; ++j) {
                            visit[y][x].pop_back();
                        }

                    }

                } else if (map[ny][nx] == 2) {

                    v[i].dir = dir;
                }

        }
    }
}

int main(){


    scanf("%d %d",&n,&k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&map[i][j]);
        }
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d",&a,&b,&c);
        v.push_back({a-1,b-1,c-1,i});
        visit[a-1][b-1].push_back(v[i]);
    }

    game();

    if(flag) printf("%d",-1);
    else {
        printf("%d", ans);
    }
}