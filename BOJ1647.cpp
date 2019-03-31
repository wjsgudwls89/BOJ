//
// Created by ÀüÇüÁø on 2019-03-31.
//
#include <cstdio>
#include <algorithm>

using namespace std;
struct HOUSE {
	int a;
	int b;
	int c;
};
HOUSE house[1000001];
int parent[100001];
int sum = 0;
int n, m;
bool cmp(HOUSE l1, HOUSE l2) {
	return l1.c < l2.c;
}
int getParent(int parent[], int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent, parent[x]);
}
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		return parent[b] = a;
	else parent[a] = b;
}
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	return 0;
}
int main() {
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
		scanf_s("%d %d %d", &house[i].a, &house[i].b, &house[i].c);
	
	for (int i =0; i < n; i++)
		parent[i] = i;

	int idx = 0;

	sort(house, house+m, cmp);

	for (int i = 0; i < m; i++) {

		if (!findParent(parent, house[i].a, house[i].b)) {
			idx++;
			sum += house[i].c;
			unionParent(parent, house[i].a, house[i].b);
		}
		if (idx == n - 2) {
			break;
		}
	}
	printf("%d", sum);
	return 0;
}