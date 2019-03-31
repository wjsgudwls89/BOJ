//
// Created by ÀüÇüÁø on 2019-03-31.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int>a[32001];

int degree[32001];
int n, k;
int A, B;

void sort() {
	int result[32001];
	queue <int>q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (--degree[y] == 0)
				q.push(y);
		}

	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d %d", &A, &B);
		a[A].push_back(B);
		degree[B]++;
	}
	sort();
}
