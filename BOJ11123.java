package algo_;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ11123 {
	static int test;
	static int h,w;
	static char[][] map = new char[101][101];
	static int dx[] = {1,0,-1,0};
	static int dy[] = {0,1,0,-1};
	static boolean[][] visit;
	
	
	public static void BFS(int y,int x) {
		Queue<sheep> q = new LinkedList<>();
		q.offer(new sheep(y,x));
		
		visit[y][x] = true;
		
		while(!q.isEmpty()) {
			int ay = q.peek().y;
			int ax = q.peek().x;
			q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = ax+ dx[i];
				int ny = ay +dy[i];
				
				if(nx>=0 && ny>=0 && nx<w && ny< h && map[ny][nx] == '#' &&
						visit[ny][nx] == false) {
					q.offer(new sheep(ny,nx));
					visit[ny][nx] = true;
				}
			}

		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		test = sc.nextInt();
		
		for (int t = 0; t < test; t++) {
			h = sc.nextInt();
			w= sc.nextInt();
			int cnt = 0;
			sc.nextLine();
			visit = new boolean[101][101];
			for (int i = 0; i < h; i++) {
				String s = sc.nextLine();
					for (int j = 0; j < s.length(); j++) {
						map[i][j] = s.charAt(j);
						if(map[i][j] == '.') { visit[i][j] = true;}
					}
				}
	
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if(map[i][j] == '#' && visit[i][j] == false) {
						BFS(i,j);
						cnt++;
					}
				}
			}
			System.out.println(cnt);
			}
		}
	static class sheep{
		int y;
		int x;
		
		public sheep(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
		
		
	}

	}


