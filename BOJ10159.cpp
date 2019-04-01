//
// Created by ÀüÇüÁø on 2019-04-01.
//
#include <stdio.h>
#include <algorithm>

int arr[106][106];
int d[106][106];

int n, m;
int a, b;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

void sol() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = arr[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] && d[k][j])
					d[i][j] = 1;
			}
		}
	}
}

int main() {

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			if (i == j)
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a - 1][b - 1] = 1;
	}

	sol();

	int k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == 0 && d[j][i] == 0)
				k++;
		}
		printf("%d\n", k);
		k = 0;

	}

}
