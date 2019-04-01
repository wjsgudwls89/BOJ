#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

int dz[] = { 1,0,0,-1,0,0 };
int dy[] = { 0,1,0,0,-1,0 };
int dx[] = { 0,0,1,0,0,-1 };
using namespace std;
char build[31][31][31];
int dis[31][31][31];

int sz, sy, sx;
int l, r, c;
void bfs(int z, int y, int x) {
	queue<int>xq;
	queue<int>yq;
	queue<int>zq;


	build[z][y][x] = '#';
	dis[z][y][x] = 0;

	xq.push(x);
	yq.push(y);
	zq.push(z);

	while (!xq.empty()) {
		x = xq.front();
		y = yq.front();
		z = zq.front();
		xq.pop(); yq.pop(); zq.pop();


		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx >= 0 && nx < c && ny >= 0 && ny < r && nz >= 0 && nz < l) {
				if (build[nz][ny][nx] == '.') {
					xq.push(nx);
					yq.push(ny);
					zq.push(nz);
					build[nz][ny][nx] = '#';
					dis[nz][ny][nx] = dis[z][y][x] + 1;
				}
				else if (build[nz][ny][nx] == 'E') {
					printf("Escaped in %d minute(s).\n", dis[z][y][x] + 1);
					return;
				}
			}
		}
	}
	printf("Trapped!\n");
}
int main() {
	/*while (true) {
		scanf_s("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0)
			break;
		getchar();

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				gets_s(build[i][j]);
			}
			if (i == l - 1)
				break;
			else
				getchar();
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					if (build[i][j][k] == 'S') {
						 bfs(k, j, i);
					}
				}
			}
		}
	}*/
	while (true) {
		cin >> l >> r >> c;
		if (l == 0) break;
		//memset(dist, 0, sizeof(dist));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> build[i][j][k];
					if (build[i][j][k] == 'S') sx = k, sy = j, sz = i;
					//else if (build[i][j][k] == 'E') ex = i, ey = j, ez = k;
				}
			}
		}
		bfs(sz,sy,sx);
	}
	return 0;
}


