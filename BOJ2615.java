package algo_basic.day6;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ2615 {


	static int[] dx = {1,1,1 ,0};
	static int[] dy = {-1,0,1,1 };
	static int map[][] = new int[21][21];
	static int visit[][] = new int[21][21];
	static boolean flag =true;
	static int cnt = 0;

	public static void DFS(int depth,int y,int x,int bw,int dir,int ansi,int ansj) {

		if(depth==4) {
			//flag = false;
			if(map[ansi+dy[dir]*(-1)][ansj+dx[dir]*(-1)] == bw || map[y+dy[dir]][x+dx[dir]] == bw) {flag = true;
			return;
			}
			else{flag = false;

			return;
			}
		}
		else {
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if(ny<1 || nx<1 || ny>20 || nx > 20)
				return;
			if(map[ny][nx] ==bw && visit[ny][nx] ==0) {
				visit[ny][nx] = 1;
				DFS(depth+1,ny,nx,bw,dir,ansi,ansj);

			}
			else return;
		}

		return;
	}

	public static void main(String[] args){
		//System.setIn(new FileInputStream("Test5.txt"));
		Scanner sc = new Scanner(System.in);
		// 구현하세요.



		for (int i = 1; i < 20; i++) {
			for (int j = 1; j < 20; j++) {
				map[i][j] = sc.nextInt();
			}
		}

		for (int i = 1; i < 20; i++) {
			for (int j = 1; j < 20; j++) {
				if(map[i][j] == 0) continue;
				else {
					if(visit[i][j] == 1) continue;
					for (int k = 0; k < 4; k++) {
						visit = new int[21][21];
						DFS(0,i,j,map[i][j],k,i,j);
									
						//visit[i][j] = 0;
						if(!flag) {
						System.out.printf("%d\n",map[i][j]);
						System.out.printf("%d %d",i,j);
						System.exit(0);
						}
						
					}
				}
			}
		}
		if(flag) System.out.println("0");



	}

}