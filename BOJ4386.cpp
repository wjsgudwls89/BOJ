//
//  BOJ4386.cpp
//  BOJ
//
//  Created by 전형진 on 27/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct NODE {
	double x;
	double y;
}node[101];

struct EDGE {
	double distance;
	int line[2];
}edge[10001];

bool cmp(EDGE l1, EDGE l2) {
	return l1.distance < l2.distance;
}

double sum = 0;

int parent[101];

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		return parent[b] = a;
	else
		return parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

	


int main() {

	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int k = n;
	for (int i = 0; i < n; i++) {
		scanf_s("%lf %lf", &node[i].x, &node[i].y);
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edge[idx].line[0] = i+1;
			edge[idx].line[1] = j+1;
			edge[idx].distance = sqrt(powf((node[j].x - node[i].x), 2)
				+ powf((node[j].y - node[i].y), 2));
			idx++;
		}
	}
	sort(edge, edge + idx, cmp);

	for (int i = 0; i < idx; i++) {
		if (!findParent(parent, edge[i].line[0] , edge[i].line[1] )) {
			sum += edge[i].distance;
			unionParent(parent, edge[i].line[0] , edge[i].line[1] );
		}
	}
	printf("%.2lf",sum);
	return 0;
}

