package com.ssafy.algo;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ3109 {
	static int r,c;
	static int[][] visit = new int[10001][501];
	static char[][] map = new char[10001][501];
	static int dx[] = {1,1,1};
	static int dy[] = {-1,0,1};
	static int cnt = 0;
	static int ans = 0;
	static boolean flag = false;
	public static void DFS(int y, int x) {
		if(x == c-1) {
					cnt++;
					flag = true;

			return;
		}


		for (int i = 0; i < 3; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];

			if(nx>=0 && ny >=0 && ny<r && nx <c &&map[ny][nx] == '.' 
					&& visit[ny][nx] == 0) {
				visit[ny][nx] = 2;
				DFS(ny,nx);
				if(flag) return;
			}
		}


	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		r=sc.nextInt();
		c= sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < r; i++) {
			String a = sc.nextLine();
			for (int j = 0; j < a.length(); j++) {
				map[i][j] = a.charAt(j);
				if(map[i][j] == 'x') {
					visit[i][j] = 1;
				}
			}
		}


		for (int i = 0; i < r; i++) {
			flag = false;
			DFS(i,0);
		}

		System.out.println(cnt);

	}

}
