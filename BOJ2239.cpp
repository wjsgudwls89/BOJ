//
// Created by 전형진 on 2020-03-18.
//
#include <stdio.h>
#include <vector>
using namespace std;
struct POS{
    int y;
    int x;
};
vector<POS> v;

int map[9][9];
bool flag = false;
bool check1(int x,int num){
    for (int i = 0; i < 9; ++i) {
        if(map[i][x] == num)
            return false;
    }
    return true;
}
bool check2(int y,int num){
    for (int i = 0; i < 9; ++i) {
        if(map[y][i] == num)
            return false;
    }
    return true;
}
bool check3(int y,int x,int num){
    int tempx = 0;
    int tempy = 0;

    if(y/3 == 0){
        tempy = 0;
    }
    else if(y/3 == 1){
        tempy = 3;
    }
    else if(y/3 == 2){
        tempy = 6;
    }
    if(x/3 == 0){
        tempx = 0;
    }
    else if(x/3 == 1){
        tempx = 3;
    }
    else if(x/3 == 2){
        tempx = 6;
    }

    for (int i = tempy; i < tempy+3 ; ++i) {
        for (int j = tempx; j < tempx+3; ++j) {
            if(map[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

void DFS(int depth){
    if(flag) return;
    if(depth == v.size()){
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d",map[i][j]);
            }
            printf("\n");
        }
        flag = true;
        return;
    }

    int y = v[depth].y;
    int x = v[depth].x;

    for (int i = 1; i <= 9; ++i) {
        if(check1(x,i) && check2(y,i) && check3(y,x,i)){
            map[y][x] = i;
            DFS(depth+1);
            map[y][x] = 0;
        }
    }

}
int main(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%1d", &map[i][j]);

            if (map[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }

    DFS(0);
}