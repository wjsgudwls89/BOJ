package com.ssafy.algo;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ2194 {
	static int[][] visit = new int[501][501];
	static int[][] map = new int[501][501];
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static int n,m,a,b,k;
	static int sy,sx,ey,ex;
	static int cnt = 0;
	static boolean flag = false;
	public static boolean check(int y,int x) {

		for (int i = y; i < y+a; i++) {
			for (int j = x; j < x+b; j++) {
				if(i>n || j>n || i<1 || j<1 ) return false;
				if(map[i][j] == 1) return false;
				
			}
		}
		return true;

	}
	public static void BFS(int ay,int ax) {
		Queue<Integer> xq = new LinkedList<>();
		Queue<Integer> yq = new LinkedList<>();

		visit[ay][ax] = 1;
		xq.offer(ax);
		yq.offer(ay);

		while(!xq.isEmpty()) {
			int qs = xq.size();
			while(qs>0) {
				int x = xq.poll();
				int y = yq.poll();
				if(y == ey && x == ex) { 
					flag = true;
					System.out.println(cnt);
					}
				if(check(y,x)) {
					for (int i = 0; i < 4; i++) {
						int nx = x+dx[i];
						int ny = y+dy[i];

						if(nx>0 && ny>0 && nx<=n && ny<=n &&visit[ny][nx] == 0) {
							xq.offer(nx);
							yq.offer(ny);
							visit[ny][nx] = 1;
						}
					}
				}
				qs--;
			}
			cnt++;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		m = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();
		k = sc.nextInt();

		for (int i = 0; i < k; i++) {
			int ty = sc.nextInt();
			int tx = sc.nextInt();
			map[ty][tx] = 1;
			visit[ty][tx] = 1;
		}
		sy = sc.nextInt();
		sx = sc.nextInt();
		ey = sc.nextInt();
		ex = sc.nextInt();
		
		BFS(sy,sx);
		if(!flag)
			System.out.println("-1");
		
	}

}
