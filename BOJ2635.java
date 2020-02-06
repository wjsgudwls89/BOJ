package com.ssafy.algo;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BOJ2635 {
	static int cnt = Integer.MIN_VALUE;
	static int len;
	static List<Integer> ans = new ArrayList<>();
	static List<Integer> myans = new ArrayList<>();
	public static void DFS(int a,int b) {
		if(a-b < 0) {
			if(cnt < ans.size()) {
				myans.clear();
				cnt = ans.size();
				myans.addAll(ans);
			}
			
			ans.clear();
			return;
		}
		else {
			int temp = a;
			a = b;
			b = temp-b;
			ans.add(b);
			DFS(a,b);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		
		int k = sc.nextInt();
		for (int i = 0; i < k; i++) {
			ans.add(k);
			ans.add(k-i);
			DFS(k,k-i);
		}
		System.out.println(cnt);
		for (int i = 0; i < myans.size(); i++) {
			System.out.printf("%d ",myans.get(i));
		}
	}

}
