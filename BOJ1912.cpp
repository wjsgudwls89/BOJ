#include <stdio.h>
int arr[100001];
int sol[100001];
int n;
int max = 0;
int sum = 0;
int getMax(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}

int main() {
	int a;
	int temp = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	sol[0] = arr[0];
	max = arr[0];
	for (int i = 1; i < n; i++) {
		sol[i] = getMax(arr[i], sol[i - 1] + arr[i]);
		max = getMax(max, sol[i]);
	}
	printf("%d", max);
}