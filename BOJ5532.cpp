#include <stdio.h>

int compare(int x, int y) {
	if (x < y)
		return y;
	else
		return x;
}


int main() {
	int l, a, b, c, d;
	int com1;
	int com2;
	int sum;
	
	scanf_s("%d", &l);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	
	if (a%c != 0 && b%d != 0) {
		com1 = a / c;
		com2 = b / d;
		sum = compare(com1, com2);

		printf("%d", l - sum - 1);
	}
	else if (a%c != 0 && b % d == 0) {
		com1 = a / c;
		com2 = b / d;
		sum = compare(com1, com2);
		if(sum == com1)
		printf("%d", l - sum - 1);
		else
			printf("%d", l - sum);
	}
	else if (a%c == 0 || b % d != 0) {
		com1 = a / c;
		com2 = b / d;
		sum = compare(com1, com2);
		if (sum == com2)
			printf("%d", l - sum - 1);
		else
			printf("%d", l - sum);
	}
	else {
		com1 = a / c;
		com2 = b / d;
		sum = compare(com1, com2);
		printf("%d",l-sum);
	}
}