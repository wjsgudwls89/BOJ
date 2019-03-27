#include <stdio.h>
#include <math.h>
int dp[100001];

int main() {
	int n;
	scanf_s("%d", &n);
	//1로만 채워보기.
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1)
				dp[i] = dp[i - j * j] + 1;
		}
		
	}
	printf("%d ", dp[n]);
	

}