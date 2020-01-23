package com.ex;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ15651 {
	static int arr[];
	static boolean visit[];
	static int n,m;
	static StringBuilder sb = new StringBuilder();
	public static void DFS(int depth) {

		if(depth == m) {
			for (int i = 0; i < m; i++) {
				sb.append(arr[i]+1).append(' ');
			}
			sb.append('\n');
			return;
		}
	
			for (int i = 0; i < arr.length; i++) {
					arr[depth] = i;
					DFS(depth+1);
			}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 m = sc.nextInt();
		 arr = new int[n];
		 //visit = new boolean[n];
		 DFS(0);
		 System.out.println(sb);
		
	}

}
