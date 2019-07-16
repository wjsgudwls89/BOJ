//
// Created by 전형진 on 2019-07-16.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;
struct check{
    char a;
    int pre;
}CHECK[100001];


int visit[100001];

int a,b;
int d[5];
int td[5];
void getDigit(int num){
    int k = 1000;
    for (int i = 1; i <= 4; ++i) {
        d[i] = num/k;
        num-=k*d[i];
        k/=10;
    }
}
void bfs(int n,int b){
    queue<int> q;
    visit[n] = 1;
    q.push(n);
    int cnt = 0;

    while(!q.empty()){

        int qs = q.size();
        while(qs--){
            int x = q.front();
            visit[x] = 1;
            if(x == b){
                //printf("%d %d %d %d\n",D,S,L,R);
               // printf("%d",cnt);
                return;
            }
            q.pop();
            getDigit(x);
            int nx;
            for (int i = 0; i <4; ++i) {
                if(i ==0){
                    nx = (x*2) % 10000;
                    //D++;
                }
                else if(i ==1){
                    if(x == 0){
                        nx = 9999;
                    }
                    else
                        nx = x - 1;

                    //S++;
                }
                else if(i ==2){
                    td[1] = d[2];
                    td[2] = d[3];
                    td[3] = d[4];
                    td[4] = d[1];
                    nx = ((td[1]*10+td[2])*10+td[3])*10+td[4];
                   // L++;

                }
                else if(i ==3){
                    td[1] = d[4];
                    td[2] = d[1];
                    td[3] = d[2];
                    td[4] = d[3];
                    nx = ((td[1]*10+td[2])*10+td[3])*10+td[4];
                    //R++;
                }
                if(visit[nx] == 0){
                    q.push(nx);
                    visit[nx] = 1;
                    if(i==0){
                        CHECK[nx].a = 'D';
                        CHECK[nx].pre = x;
                    }
                    if(i==1){
                        CHECK[nx].a = 'S';
                        CHECK[nx].pre = x;
                    }
                    if(i==2){
                        CHECK[nx].a = 'L';
                        CHECK[nx].pre = x;
                    }
                    if(i==3){
                        CHECK[nx].a = 'R';
                        CHECK[nx].pre = x;
                    }
                }
            }
        }
        cnt++;
    }

}
int main(){
    int test;
    scanf("%d",&test);
    for (int j = 0; j <test ; ++j) {
        vector<char> ans;
        scanf("%d %d", &a, &b);

        CHECK[a].pre = 10000;
        bfs(a, b);
        while (1) {
            ans.push_back(CHECK[b].a);
            b = CHECK[b].pre;
            if (CHECK[b].pre == 10000) {
                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            printf("%c", ans[i]);
        }
        printf("\n");
        ans.clear();
        memset(visit,0, sizeof(visit));
    }

}