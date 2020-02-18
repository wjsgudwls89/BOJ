package algo_ad.day2;

import java.util.Scanner;

public class BOJ2630 {
	static int map[][];
	static int result[] = new int[2];
	public static boolean check(int y,int x,int size) {
		for (int i = y; i < y+size; i++) {
			for (int j = x; j < x+size; j++) {
				if(map[i][j] != map[y][x]) return false;
			}
		}
		return true;
	}
	public static void ans(int y, int x, int size) {
		if(check(y,x,size)) {
			result[map[y][x]]++;
			return;
		}
		else {
			int now = size/2;
			
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					ans(y + i * now, x + j * now, now);
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		
		int n = sc.nextInt();
		
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		ans(0,0,n);
		for (int i = 0; i < 2; i++) {
			System.out.println(result[i]);
		}
	}
}
