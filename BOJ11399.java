package algo_ad.day2;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ11399 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int sum= 0;
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j <= i; j++) {
				sum+=arr[j];
			}
			
		}
		System.out.println(sum);
	}

}
