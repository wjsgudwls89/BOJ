//
// Created by 전형진 on 2019-10-09.
//
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int app[101][101];

int dir[10001];
struct SNAKE{
    int y = 0;
    int x = 0;
    int direction = 1;
};

SNAKE snake;
SNAKE snakeTail;
queue<SNAKE> s;

int n,k,l;

void start(){
    int i = 0;
    s.push({snake.y,snake.x});
    while(true) {
        //int tempx = snake.x, tempy = snake.y;
        if(dir[i] != 0){
            if(dir[i] == 1) {
                snake.direction++;
                if(snake.direction>4)
                    snake.direction = 1;
            }
            if(dir[i] == 2){
                snake.direction--;
                if(snake.direction<1)
                    snake.direction = 4;
            }
        }
        if(snake.direction == 2){
            snake.y++;
            //tempy++;
        }
        if(snake.direction == 1){
            snake.x++;
           // tempx++;
        }
        if(snake.direction == 4){
            snake.y--;
            //tempy--;
        }
        if(snake.direction == 3){
            snake.x--;
            //tempx--;
        }
        i++;
        if(snake.x >=n || snake.y >=n || snake.y<0 || snake.x < 0)
            break;
        if(map[snake.y][snake.x] == 1)
            break;
        else {
            map[snake.y][snake.x] = 1;
            s.push({snake.y, snake.x});
        }

        if(app[snake.y][snake.x] == 0) {
            map[snakeTail.y][snakeTail.x] = 0;
            s.pop();
            snakeTail.y = s.front().y;snakeTail.x = s.front().x;

            //snakeTail.y=tempy; snakeTail.x = tempx;
        }
        else {
            app[snake.y][snake.x] = 0;
            snakeTail.y = s.front().y;snakeTail.x = s.front().x;
        }

    }
    printf("%d", i);
}

int main(){

    scanf("%d",&n);
    memset(map, 0,sizeof(map));
    memset(app,0,sizeof(app));
    memset(dir,0, sizeof(dir));

    map[0][0] = 1;

    scanf("%d",&k);

    for (int i = 0; i < k; ++i) {
        int c,l;
        scanf("%d %d",&c,&l);
        app[c-1][l-1] = 1;
    }
    scanf("%d",&l);
    for (int i = 0; i < l; ++i) {
        int t;
        char d;
        scanf("%d %c",&t,&d);
        if(d == 'D') dir[t] = 1;
        else dir[t] = 2;
    }
    start();
}