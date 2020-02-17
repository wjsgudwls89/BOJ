package algo_ad.day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ10972 {
	static boolean flag = false;
	static int n;
	static int[] src;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
//		
//		n = Integer.parseInt(bf.readLine());
		
		
		n = Integer.parseInt(bf.readLine());
		src = new int[n];
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			src[i] = Integer.parseInt(st.nextToken());
			
		}
		StringBuilder sb = new StringBuilder();
		if(nextPermutation()) {
			for (int i = 0; i < 4; i++) {
				sb.append(src[i]).append(" ");
			}
			System.out.println(sb);
		}
		else {System.out.println(-1);}
	}
	private static boolean nextPermutation() {
		int i;
		for(i = src.length-2 ; i>=0 ; i --) {
			if(src[i] < src[i+1]) {
				break;
			}
		}
		if(i<0) {
			return false;
		}
		
		int j;
		for(j = src.length-1; j > i ; j--) {
			if(src[i] < src[j]) {
				break;
			}
		}
		swap(i, j);
		for (int a = i+1, b = src.length-1 ; a < b; a++,b--) {
			swap(a,b);
		}
		return true;
	}
	public static void swap(int a, int b) {
		int temp = src[a];
		
		src[a] = src[b];
		src[b] = temp;
	}
}
