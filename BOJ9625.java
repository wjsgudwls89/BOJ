package com.ssafy.algo;

import java.util.Scanner;

public class BOJ9625 {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[][] arr = new int[46][2];
		int k = sc.nextInt();
		
		arr[0][0] = 1;
		arr[0][1] = 0;
		arr[1][0] = 0;
		arr[1][1] = 1;
		
		for (int i = 2; i <= 45; i++) {
			arr[i][0] = arr[i-1][0]+arr[i-2][0];
			arr[i][1] = arr[i-1][1]+arr[i-2][1];
		}
		System.out.println(arr[k][0] + " " + arr[k][1]);
		
		
	}

}
