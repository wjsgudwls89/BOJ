//
// Created by 전형진 on 2020-03-15.
//
#include <stdio.h>

using namespace std;
int n;
int map[17][17];
int dx[] = {1,1,0};
int dy[] = {0,1,1};
int ans = 0;
void DFS(int y,int x,int dir){
   // printf("%d %d\n",y,x);
    if(y == n-1 && x == n-1){
        ans++;
        return;
    }
    else{
        if(dir == 1){ //가로
            int nx = x;
            int ny = y;
            for (int i = 0; i < 2; ++i) {
                if(i == 0){
                    nx++;
                    if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                        DFS(ny,nx,1);

                    }
                    nx--;
                }
                if(i == 1){
                    int temp = 0;
                    for (int j = 0; j < 3; ++j) {
                        nx  = x + dx[j];
                        ny  = y + dy[j];
                        if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                            temp++;
                        }
                    }
                    if(temp == 3){
                        nx = x+1;
                        ny = y+1;
                        DFS(ny,nx,3);
                    }
                }
            }
        }
        else if(dir == 2){//세로
            int nx = x;
            int ny = y;
            for (int i = 0; i < 2; ++i) {
                if(i == 0){
                    ny++;
                    if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                        DFS(ny,nx,2);

                    }
                    ny--;
                }
                if(i == 1){
                    int temp = 0;
                    for (int j = 0; j < 3; ++j) {
                        nx  = x + dx[j];
                        ny  = y + dy[j];
                        if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                            temp++;
                        }
                    }
                    if(temp == 3){
                        nx = x+1;
                        ny = y+1;
                        DFS(ny,nx,3);
                    }
                }
            }

        }
        else if(dir == 3){//대각
            int nx = x;
            int ny = y;
            for (int i = 0; i < 3; ++i) {
                if(i == 0){
                    nx++;
                    if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                        DFS(ny,nx,1);

                    }
                    nx--;
                }
                if(i == 1){
                    ny++;
                    if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                        DFS(ny,nx,2);

                    }
                    ny--;
                }
                if(i == 2){
                    int temp = 0;
                    for (int j = 0; j < 3; ++j) {
                        nx  = x + dx[j];
                        ny  = y + dy[j];
                        if(nx>=0 && ny>=0 && nx<n && ny <n && map[ny][nx] == 0){
                            temp++;
                        }
                    }
                    if(temp == 3){
                        nx = x+1;
                        ny = y+1;
                        DFS(ny,nx,3);
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&map[i][j]);
        }
    }
    DFS(0,1,1);
    printf("%d",ans);
}