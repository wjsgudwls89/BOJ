//
// Created by 전형진 on 2020-05-10.
//
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
double map[50][50];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
struct POS{
    int y;
    int x;
};
int visit[50][50];
int t;
int n,m;
int x,d,k;
double ans;
bool BFS(int y,int x){
    bool flag = false;
    queue<POS> q;
    q.push({y,x});
    int temp = map[y][x];
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0) nx = m-1;
            else if(nx == m) nx = 0;

            if(nx>=0 && ny >=0 && nx<m && ny<n && map[ny][nx] == temp && visit[ny][nx] ==0){
                map[ny][nx] = 0;
                q.push({ny,nx});
                visit[y][x] = 1;
                flag = true;
            }
        }

    }

    return flag;
}
double getSum(bool flag){
    double sum = 0;
    double cnt = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += map[i][j];
            if (map[i][j] != 0) cnt++;
        }
    }
    //printf("%lf %lf",sum,cnt);
    if(flag)
        return sum;
    else return sum/cnt;
}
void check(){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] != 0){
                if(BFS(i,j)){
                    cnt++;
                    if(visit[i][j] == 1) map[i][j] = 0;

                }

            }
        }
    }

    memset(visit,0, sizeof(visit));
    if(cnt == 0){
        double temp = getSum(false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(map[i][j] == 0) continue;
                else{
                    if(map[i][j] > temp) map[i][j] -=1;
                    else if(map[i][j] < temp) map[i][j]+=1;
                    else continue;
                }
            }
        }
        ans = getSum(true);
    }
    else{
       ans = getSum(true);
    }

}

void round(int x,int d,int k){
  if(d == 1) k = m - (k%m);
        for (int i = 0; i < n; ++i) {
            double temp[50];
            if((i+1)%x == 0){
                for (int j = 0; j < m; ++j) {
                    int move = (j+k) % m;

                        temp[move] = map[i][j];

                }
                memcpy(map[i],temp, sizeof(temp));
            } else continue;

        }

//    else{
//        for (int i = 0; i < n; ++i) {
//            int temp[50];
//            if((i+1)%x == 0){
//                for (int j = 0; j < m; ++j) {
//                    int move = - (k%m);
//                    if(move < 0){
//                        temp[j+(m+move)] = map[i][j];
//                    }
//                    else{
//                        temp[move] = map[i][j];
//                    }
//                    printf("%d %d\n",move,temp[move]);
//                }
//                memcpy(map[i],temp, sizeof(m));
//            } else continue;
//
//        }
//    }
}

int main(){
    scanf("%d %d %d",&n,&m,&t);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lf",&map[i][j]);
        }
    }
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d",&x,&d,&k);
        round(x,d,k);
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                printf("%lf ",map[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        check();
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                printf("%lf ",map[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");

    }

    printf("%d",(int)ans);

}