#include <stdio.h>

int stair[301];
int dp[301];

int Max(int a, int b) {
	return a > b ? a : b;
}
int sol(int n) {
	dp[0] = stair[0];
	dp[1] = Max(stair[1], stair[0] + stair[1]);
	dp[2] = Max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = Max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	return dp[n-1];
}
int main(void) {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &stair[i]);
	}
	printf_s("%d", sol(n));


}