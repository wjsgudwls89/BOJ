package algo_basic.day10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class BOJ17471 {
	static int V;
	static int[] visit = new int[11];
	static int[] div;
	static int[] temp1;
	static int[] temp2;
	static List<town> bk = new ArrayList<>();
	static List<Integer>[] map = new List[11];
	static int ans = Integer.MAX_VALUE;
	public static void Find() {
		int sum1=0;
		int sum2=0;
		for (int i = 1; i <= V; i++) {
			if(visit[i] == 1) {
				sum1+=bk.get(i-1).num;
			}
			else {
				sum2+=bk.get(i-1).num;
			}
		}
		//System.out.println(sum1-sum2);
		ans  = Math.min(ans, Math.abs(sum1-sum2));
		//System.out.println(Math.abs(sum1-sum2));
	}
	public static void BFS(int start,int a) {
		Queue<Integer> q= new LinkedList<>();
		div[start] = 1;
		q.offer(start);
		
		while(!q.isEmpty()) {
			int x = q.poll();
			
			for (int i = 0; i < map[x].size(); i++) {
				int nx = map[x].get(i);
		
				if(div[nx] == 0 && visit[nx] == a) {
					div[nx] = 1;
					q.offer(nx);
				}
			}
		}
		
	}
	public static void DFS(int start,int depth,int c) {
		if(depth ==c) {
			
			int idx = 0;
			for (int i = 1; i <= V; i++) {
				if(visit[i] ==0) {
					temp2[idx] = i;
					idx++;
				}
			}
			div = new int[V+1];
			BFS(temp1[0],1);
			BFS(temp2[0],0);
//			System.out.println(Arrays.toString(temp1));
//			System.out.println(Arrays.toString(temp2));
//			System.out.println(Arrays.toString(visit));
//			System.out.println(Arrays.toString(div));
			int cnt = 0;
			for (int i = 1; i <= V; i++) {
				if(div[i] == 1)
					cnt++;
			}
			if(cnt == V) {
				Find();
			}
			else {return;}
			
			return;
		}
		
		for (int i = start; i <= V; i++) {
			if(visit[i] == 0) {
				visit[i] = 1;
				temp1[depth] = i;
				DFS(i+1,depth+1,c);
				visit[i] = 0;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		
		for (int i = 1; i <= V; i++) {
			int num = sc.nextInt();
			bk.add(new town(num));
			map[i] = new ArrayList<>();
		}
		//System.out.println(bk.toString());
		for (int i = 1; i <= V; i++) {
			int link = sc.nextInt();
			
			for (int j = 0; j < link; j++) {
				int dus =sc.nextInt();
				
				map[i].add(dus);
				map[dus].add(i);
			}
		}
		for (int i = 1; i <=V/2; i++) {
			temp1 = new int[11];
			temp2 = new int[11];
			DFS(1,0,i);
		}
		if(ans == Integer.MAX_VALUE) {System.out.println("-1");}
		else System.out.println(ans);
		
	}
	static class town{
		int num;

		public town(int num) {
			super();
			this.num = num;
		}

		@Override
		public String toString() {
			return "town [num=" + num + "]";
		}
		
	}

}
