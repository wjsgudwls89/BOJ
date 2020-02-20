package com.ssafy.algo;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ14503 {
	static int n,m;
	static int map[][];
	static boolean visit[][];
	static int dx[] = new int[4];
	static int dy[] = new int[4];
	static int d;
	static int clear = 1;
	public static void cDir(int d) {
		if(d ==0) {
			dx[0] = -1;dy[0] =  0;
			dx[1] =  0;dy[1] =  1;
			dx[2] =  1;dy[2] =  0;
			dx[3] =  0;dy[3] = -1;
		}
		else if(d==1) {
			dx[0] =  0;dy[0] = -1;
			dx[1] = -1;dy[1] =  0;
			dx[2] =  0;dy[2] =  1;
			dx[3] =  1;dy[3] =  0;
		}
		else if(d==2) {
			dx[0] =  1;dy[0] =  0;
			dx[1] =  0;dy[1] = -1;
			dx[2] = -1;dy[2] =  0;
			dx[3] =  0;dy[3] =  1;
		}
		else if(d==3) {
			dx[0] =  0;dy[0] =  1;
			dx[1] =  1;dy[1] =  0;
			dx[2] =  0;dy[2] = -1;
			dx[3] = -1;dy[3] =  0;
		}
	}
	public static void DFS(int sy, int sx,int dir) {
		if(!visit[sy][sx]) {visit[sy][sx] = true; map[sy][sx] =2;}
//		for (int i = 0; i < n; i++) {
//			System.out.println(Arrays.toString(map[i]));
//		}
//		System.out.println(dir);
//		System.out.println("--------------------------------------------------------");
		cDir(dir);
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = sy+dy[i];
			int nx = sx+dx[i];
			cnt++;
			if(nx>=0 && ny >=0 && ny<n && nx<m) {
				if(map[ny][nx] == 0 && !visit[ny][nx]) {
					dir--;
					clear++;
					if(dir<0) dir=3;
					DFS(ny,nx,dir);
				}
				else if(map[ny][nx] == 1 || visit[ny][nx]) {
					dir--;
					if(dir<0) dir=3;
				}
			}
		}
			if(cnt ==4) {
				if(dir==0) {
					sy++;
					if(map[sy][sx] == 1) {
//						for (int i = 0; i < n; i++) {
//							System.out.println(Arrays.toString(map[i]));
//						}
						System.out.println(clear);
						System.exit(0);
					}
					
					DFS(sy,sx,dir);
				}
				if(dir==1) {
					sx--;
					if(map[sy][sx] == 1) {
//						for (int i = 0; i < n; i++) {
//							System.out.println(Arrays.toString(map[i]));
//						}
						System.out.println(clear);
						System.exit(0);
					}
					DFS(sy,sx,dir);
				}
				if(dir==2) {
					sy--;
					if(map[sy][sx] == 1) {
//						for (int i = 0; i < n; i++) {
//							System.out.println(Arrays.toString(map[i]));
//						}
						System.out.println(clear);
						System.exit(0);
					}
					DFS(sy,sx,dir);
				}
				if(dir==3) {
					sx++;
					if(map[sy][sx] == 1) {
//						for (int i = 0; i < n; i++) {
//							System.out.println(Arrays.toString(map[i]));
//						}
						System.out.println(clear);
						System.exit(0);
					}
					DFS(sy,sx,dir);
				}
			}
		
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		map = new int[n+1][m+1];
		visit = new boolean[n+1][m+1];
		int ry = sc.nextInt();
		int rx = sc.nextInt();
		d = sc.nextInt();
		
		Bot bot = new Bot(ry,rx,d);
		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 1) visit[i][j] = true;
			}
		}
		
		DFS(bot.y,bot.x,d);
		
		
	}
	
	
	static class Bot{
		int y;
		int x;
		int d;
		public Bot(int y, int x, int d) {
			super();
			this.y = y;
			this.x = x;
			this.d = d;
		}
		
		
	}
}
