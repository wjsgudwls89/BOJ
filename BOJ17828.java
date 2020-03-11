package algo_;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ17828 {
	static int n;
	static int m;
	static int[] arr;
	static int[] temp;
	static int sum = 0;
	static boolean flag = false;
	static char[] ans = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	public static void DFS(int depth,int start) {
		if(flag) return;
		if(depth == n && sum == m) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < temp.length; i++) {
				sb.append(ans[temp[i]-1]);
			}
			System.out.println(sb);
			flag = true;
			arr = temp;
			return;
		}
		if(depth==n) return;
		if(sum>m) return;
		for (int i = start; i < 26; i++) {
			temp[depth] = i+1;
			sum+=i+1;
			DFS(depth+1,i);
			sum-=i+1;
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		arr = new int[n];
		temp = new int[n];
		if(n*26 < m || m < n) System.out.println("!");
		else {
		DFS(0,0);
		if(!flag) System.out.println("!");
		}
	}
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//		StringBuilder sb = new StringBuilder();
//		Scanner sc = new Scanner(System.in);
//		n = sc.nextInt();
//		m = sc.nextInt();
//		arr = new int[n];
//		temp = new int[n];
//		char[] getans = new char[n];
//		for (int i = 0; i < getans.length; i++) {
//			getans[i] = 'A';
//		}
//		if(n*26 < m || m < n) System.out.println("!");
//		else {
//			m -= n;
//			if(m > 25) {
//				int idx = n - 1;
//				while(m>25) {
//					getans[idx] +=25;
//					m -= 25;
//					idx--;
//				}
//				getans[idx] += m;
//			}else {
//				getans[n-1] +=m;
//			}
//			
//			for (int i = 0; i < getans.length; i++) {
//				sb.append(getans[i]);
//			}
//			System.out.println(sb);
//		}
//	}

}
