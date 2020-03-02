//
// Created by 전형진 on 2020-03-01.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;
int arr[10000];

int visit[10000];
char temp[10] = {'0','1','2','3','4','5','6','7','8','9'};
int test;
string str1;
string str2;
string tstr;
bool flag = false;
int amin = 9999;
int cnt = 0;
void prime(int n){
    if(n<= 1) return;

    for (int i = 2; i * i <= 10000 ; ++i) {
        if(!arr[i])
            for (int j = i * i; j <= 10000 ; j+=i) {
                arr[j] = 1;
            }
    }
}
void BFS(string str){
    queue<string> q;
    int num = stoi(str);
    visit[num] = 1;
    q.push(str);

    while(!q.empty()){
        int qs = q.size();
        while(qs--) {
            string atemp = q.front();
            q.pop();
            if (atemp == str2) {
                printf("%d\n",cnt);
                flag = true;
                return;
            }

            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 10; ++j) {
                    string tstr = atemp;
                    tstr[i] = temp[j];
                    int tnum = stoi(tstr);
                    if (tnum >= 1000 && !arr[tnum] && visit[tnum] == 0) {
                        visit[tnum] = 1;
                        q.push(tstr);
                    }
                }
            }
        }
        cnt++;
    }
}
int main(){
    prime(10000);
    scanf("%d",&test);


    for (int i = 0; i < test; ++i) {
        memset(visit,0, sizeof(visit));
        cin>>str1;
        cin>>str2;
        BFS(str1);
        if(!flag)printf("Impossible\n");
        flag = false;
        cnt = 0;
    }





}