#include <stdio.h>

int arr[1001];

int dp(int x) {
	if (x == 1)
		return arr[1] =1;
	if (x == 2)
		return arr[2] = 2;
	if (arr[x] != 0)
		return arr[x];
	else
		return arr[x] = (dp(x - 1) + dp(x - 2))%10007;


}

int main() {
	int k;
	scanf_s("%d", &k);
	printf("%d", dp(k));
}
