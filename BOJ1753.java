package algo_;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1753 {
	static ArrayList<POS>[] list;
	static int[] dis;
	static boolean[] visit;
	static int v,e;
	public static void dijkstra(int start) {
		PriorityQueue<POS> q = new PriorityQueue<POS>();
		
		q.add(new POS(start,0));
		dis[start] = 0;
		
		while(!q.isEmpty()) {
			int cv = q.peek().next;
			q.poll();
			visit[cv] = true;
			for (int i = 0; i < list[cv].size(); i++) {
				int ncv = list[cv].get(i).next;
				int ndis = list[cv].get(i).w; 
				
				if(dis[ncv] > dis[cv] + ndis) {
					dis[ncv] = dis[cv] + ndis;
					q.add(new POS(ncv,dis[ncv]));
				}
			}
		}
	
		for (int i = 1; i <= v; i++) {
			if(visit[i]) {
				System.out.println(dis[i]);
			}
			else {
				System.out.println("INF");
			}
		}
	
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		
		int start = Integer.parseInt(br.readLine());
		list = new ArrayList[v+1];
		visit = new boolean[v+1];
		dis = new int[v+1];
		Arrays.fill(dis, Integer.MAX_VALUE);
		for (int i = 0; i <= v ; i++) {
			list[i] = new ArrayList<POS>();
		}
		for (int i = 0; i < e ; i++) {
			st = new StringTokenizer(br.readLine());
			list[Integer.parseInt(st.nextToken())].add(new POS(Integer.parseInt(st.nextToken()), 
					Integer.parseInt(st.nextToken())));
		}
		dijkstra(start);
	}
	static class POS implements Comparable<POS>{
		int next;
		int w;
		public POS(int next, int w) {
			super();
			this.next = next;
			this.w = w;
		}
		@Override
		public int compareTo(POS o) {
			// TODO Auto-generated method stub
			return w-o.w;
		}
		
		
	}
}
