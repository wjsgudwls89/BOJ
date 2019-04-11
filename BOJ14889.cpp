//
// Created by ÀüÇüÁø on 2019-04-11.
//
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int n;
int team[21][21];

int cnt = 0;

int mins = 999999;
int visit[21];

void dfs(int start,int cnt) {
	
	if (cnt == (n / 2)) {
		vector<int> ateam;
		vector<int> bteam;

		for (int i = 0; i < n; ++i) {
			if (visit[i] == true)
				ateam.push_back(i);
			else
				bteam.push_back(i);
		}
		int suma = 0;
		int sumb = 0;
		for (int i = 0; i < ateam.size(); ++i) {
			for (int j = i + 1; j < ateam.size(); ++j) {
				suma += team[ateam[i]][ateam[j]] +
					team[ateam[j]][ateam[i]];
				sumb += team[bteam[i]][bteam[j]] +
					team[bteam[j]][bteam[i]];
			}
		}

		if (abs(suma - sumb) < mins)
			mins = abs(suma - sumb);
		
	}
	else
	{
		for (int i = start; i < n; ++i) {
			if (visit[i] == false) {
				visit[i] = true;
				dfs(i + 1,cnt+1);
				visit[i] = false;
			}
		}
	}
}
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &team[i][j]);
		}
	}
	dfs(0,0);
	printf("%d\n", mins);

}