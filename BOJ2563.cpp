//
// Created by 전형진 on 2019-05-09.
//
#include <stdio.h>
#include <queue>

using namespace std;
struct START{
    int y;
    int x;
};
vector<START> s;
int map[101][101];
int visit[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,x,y;

int bfs(){
    int gcnt = 0;

    queue<int> xq;
    queue<int> yq;

    for(int i=0;i<s.size();i++){
        xq.push(s[i].x);
        yq.push(s[i].y);
    }

    while(!xq.empty()){

        int y = yq.front();
        int x = xq.front();

        yq.pop();xq.pop();

        for (int i = 0; i < 4; ++i) {

            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0&&nx<100 && ny>=0 && ny<100){
                if(map[ny][nx] == 1 && visit[ny][nx] == 0){
                    visit[ny][nx]= 1;
                    xq.push(nx);
                    yq.push(ny);
                    gcnt++;
                }
            }
        }
    }
    return gcnt;
}
int main(){
    int ans=0;
    scanf("%d",&n);
    for (int k = 0; k < n; ++k) {
        scanf("%d %d",&x,&y);
        s.push_back({y,x});
        for(int i=y;i<y+10;i++){
            for (int j = x; j <x+10 ; ++j){
                map[i][j] = 1;
            }
        }
    }
    ans=bfs();
    printf("%d",ans);
}