// BOJ.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/**/
#include <stdio.h>

int x;
int min;
int memo[100001];

void d_three(int x, int cnt) { 

	if ((memo[x] && cnt > memo[x]) || cnt > min)
		return;

	if (x == 1 && cnt<min) {
		min = cnt;
		return;
	}
	else if(x != 1){
		cnt++;
		if (x % 3 == 0) {

			d_three(x / 3, cnt);
		}
		if (x % 2 == 0) {

			d_three(x / 2, cnt);
		}

		d_three(x - 1, cnt);
	}
}

int main()
{
	scanf_s("%d", &x);
	min = x + 1;
	d_three(x, 0);
	printf_s("%d\n",min);
}