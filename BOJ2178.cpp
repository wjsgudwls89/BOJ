//
//  BOJ2178.cpp
//  BOJ
//
//  Created by 전형진 on 29/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//
/*
#include <stdio.h>
#include <queue>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int n, m;


int maze[101][101];
int dis[101][101];

int bfs1(int y, int x) {
	queue<int>xq1;
	queue<int>yq1;

	maze[y][x] = 2;
	dis[y][x] = 1;

	xq1.push(x);
	yq1.push(y);
	

	while (!yq1.empty()) {
	    x = xq1.front();
		y = yq1.front();
		xq1.pop(); yq1.pop();
		if (y == n - 1 && x == m - 1) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[ny][nx] == 1) {
				xq1.push(nx);
				yq1.push(ny);
				maze[ny][nx] = 2;
				dis[ny][nx] = dis[y][x] + 1;

			}
		}
	}
	return dis[y][x];
}
int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}
	printf("%d", bfs1(0, 0));
}
*/