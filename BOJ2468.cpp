#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n;
int d;
int rmax = 0;
int cnt;
int map[100][100];
int tmap[100][100];
int visit[100][100];
int rvisit[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int getMax(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}
void copy(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void bfs1(int y,int x) {

	queue<int> xq;
	queue<int> yq;

	rvisit[y][x] = true;
	xq.push(x);
	yq.push(y);

	while (!xq.empty()) {
		int x = xq.front();
		int y = yq.front();
		xq.pop(); yq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (tmap[ny][nx] <= d && !rvisit[ny][nx]) {
					rvisit[ny][nx] = true;
					xq.push(nx);
					yq.push(ny);
				}
			}
		}
	}

}
void bfs2(int y, int x) {
	queue<int> xq;
	queue<int> yq;

	rvisit[y][x] = true;
	xq.push(x);
	yq.push(y);

	while (!xq.empty()) {
		int x = xq.front();
		int y = yq.front();
		xq.pop(); yq.pop();
		

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!rvisit[ny][nx]) {
					rvisit[ny][nx] = true;
					xq.push(nx);
					yq.push(ny);
				}
			}
		}
	}
	cnt++;
}

int main() {
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d",&map[i][j]);
		}
	}
	for (d = 0; d <= 100; d++) {
		copy(tmap, map);
		copy(rvisit, visit);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tmap[i][j] <= d && !rvisit[i][j])
					bfs1(i, j);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!rvisit[i][j])
					bfs2(i, j);
			}
		}
		rmax = getMax(rmax, cnt);
		cnt = 0;
	}
	printf("%d", rmax);
}