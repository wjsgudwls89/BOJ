package com.ssafy.algo;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Stack;

public class BOJ2304 {
	static int N;
	static int[][] map = new int[1001][1001];
	static int maxNum;

	static int minIdx=9999;
	static int ans = 0;
	static int[][] data;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		data  = new int[N][2];
		for (int i = 0; i < N; i++) {
			data[i][0] = sc.nextInt();
			data[i][1] = sc.nextInt();
			
		}
		Arrays.sort(data,new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				return o1[0] - o2[0];
			}

		});
		
		
		
		Stack<Integer> stack = new Stack<>();
		
		stack.push(0);
		int ans = 0;
		int nx = 0;
		int maxIdx = 0;
		for (int i = 0; i < N; i++) {
			if(stack.peek() < data[i][1]) {
				stack.pop();
				maxIdx = i;
				stack.push(data[i][1]);
			}
			int x = data[i][0];
			if(i==N-1) nx= x+1;
			else nx=data[i+1][0];
			
			for (int j = x; j < nx; j++) {
				ans += stack.peek();
			}
		}
		if(data[N-1][1] < stack.peek()) {
			int preIdx = N -1;
			for (int idx = N-1; idx >= maxIdx; idx--) {
				if(data[idx][1] > data[preIdx][1]) {
					for (int x = data[idx][0]; x < data[N-1][0]; x++) {
						ans-=data[idx][1] - data[preIdx][1];
					}
					preIdx = idx;
				}
			}
		}
		System.out.println(ans);
	}

}
