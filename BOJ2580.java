package algo_basic.day11;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BOJ2580 {
	static int[][] map = new int[9][9];
	static boolean[][][][] visit = new boolean[9][9][11][3];
	static List<Num> list = new ArrayList<>();
	public static boolean check1(int x, int num) {
		for (int i = 0; i < 9; i++) {
			if(map[i][x] == num)
				return false;
		}
		return true;
	}
	public static boolean check2(int y, int num) {
		for (int j = 0; j < 9; j++) {
			if(map[y][j] == num)
				return false;
		}
		return true;
	}
	public static boolean check3(int y,int x, int num) {
		int tempy = 0;
		int tempx = 0;
		if(y/3 ==0) {
			tempy = 0;
		}
		else if(y/3 ==1) {
			tempy = 3;
		}
		else if(y/3 ==2) {
			tempy = 6;
		}
		if(x/3 ==0) {
			tempx = 0;
		}
		else if(x/3 ==1) {
			tempx = 3;
		}
		else if(x/3 ==2) {
			tempx = 6;
		}
		for (int i = tempy; i < tempy+3; i++) {
			for (int j = tempx; j < tempx+3; j++) {
				if(map[i][j] == num) {
					return false;
				}
			}
		}
		return true;
	}
	public static void DFS(int depth) {

		if(depth == list.size()) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					System.out.printf("%d ",map[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
			return;
		}


		int y = list.get(depth).y;
		int x = list.get(depth).x;

		for (int j = 1; j <= 9; j++) {
			if(check1(x,j) && check2(y,j) && check3(y,x,j)) {
				map[y][x] = j;
				DFS(depth+1);
				map[y][x] = 0;
			}
		}

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 0) {
					list.add(new Num(i,j));
				}
			}
		}

		DFS(0);

	}
	static class Num{
		int y;
		int x;
		public Num(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}

}
