package algo_basic.day9;

import java.util.Scanner;

public class BOJ2116 {
	
	static int[][] dice = new int[10001][6];
	static int[][] visit;
	static int num;
	static int sum;
	static int ans = 0;
	public static void dfs(int depth,int top) {
		
		
		if(visit[depth][0] == 1) {
			visit[depth][5] = 1;
			top = dice[depth][5];
		}
		else if(visit[depth][1] == 1) {
			visit[depth][3] = 1;
			top = dice[depth][3];
		}
		else if(visit[depth][2] == 1) {
			visit[depth][4] = 1;
			top = dice[depth][4];
		}
		else if(visit[depth][3] == 1) {
			visit[depth][1] = 1;
			top = dice[depth][1];
		}
		else if(visit[depth][4] == 1) {
			visit[depth][2] = 1;
			top = dice[depth][2];
		}
		else if(visit[depth][5] == 1) {
			visit[depth][0] = 1;
			top = dice[depth][0];
		}
		if(depth == num-1) {
			for (int i = 0; i < num; i++) {
				int cnt = 0;
				for (int j = 0; j < 6; j++) {
					//System.out.printf("%d ",visit[i][j]);
					if(visit[i][j] == 0 && cnt<dice[i][j]) {
						cnt = dice[i][j];
					}
				}
				sum+=cnt;
				
			}
			//System.out.println(sum);
			ans = Math.max(sum, ans);
			sum=0;
			return;
			}
		for (int i = 0; i < 6; i++) {
			if(dice[depth+1][i] == top) {
				visit[depth+1][i] = 1;
				dfs(depth+1,top);
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		
		num = sc.nextInt();
		
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < 6; j++) {
				dice[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < 6; i++) {
			visit = new int[10001][6];
			visit[0][i] = 1;
			dfs(0,i);
			visit[0][i] = 0;
		}
		System.out.println(ans);
		
	}

}
