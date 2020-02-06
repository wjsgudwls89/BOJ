package com.ssafy.algo;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ1244 {
	static int k;
	static int[] visit;
	public static void BOY(int idx) {
		for (int i = idx; i <= k; i++) {
			if(i%idx == 0) {
				if(visit[i] == 1) visit[i] = 0;
				else visit[i] = 1;
			}
		}
	}
	public static void GIRL(int idx) {
		int dir = 1;
		int left = 0;
		int right = 0;
		boolean flag = true;
		while(flag) {
			left = idx-dir;
			right = idx+dir;
			if(idx-dir<1 || idx+dir>k) {
				left++;
				right--;
				break;
			}
			if(visit[left] == visit[right]) {
				dir++;
			}
			else {
				left++;
				right--;
				flag = false;
			}
		}
		for (int i = left; i <= right; i++) {
			if(visit[i] == 1) visit[i] = 0;
			else visit[i] = 1;
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		k = sc.nextInt();
		
		visit = new int[k+1];
		
		for (int i = 1; i <= k; i++) {
			int of = sc.nextInt();
			visit[i] = of;
		}
		int num = sc.nextInt();
		for (int i = 0; i < num; i++) {
			int s = sc.nextInt();
			int idx = sc.nextInt();
			if(s == 1) {
				BOY(idx);
			}
			else {
				GIRL(idx);
			}
			
		}
		for (int i = 1; i <=k ; i++) {
			if(i%20 == 1 && i>1) {System.out.println();}
			System.out.printf("%d ",visit[i]);
			
		
		}
		
	}

}
