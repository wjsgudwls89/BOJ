package algo_ad.day2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ11728 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st1 = new StringTokenizer(bf.readLine());
		int n = Integer.parseInt(st1.nextToken());
		int m = Integer.parseInt(st1.nextToken());
		
		int[] arr = new int[n+m];
		
		st1 = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			
			int k = Integer.parseInt(st1.nextToken());
			arr[i] = k;
		}
		st1 = new StringTokenizer(bf.readLine());
		for (int i = n; i < n+m; i++) {
			int k = Integer.parseInt(st1.nextToken());
			arr[i] = k;
		}
		
//		int[] arr = new int[a.size()];
//		for (int i = 0; i < a.size(); i++) {
//			arr[i] = a.get(i);
//		}
		Arrays.sort(arr);
		//mergeSort(arr, 0, arr.length-1);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < arr.length; i++) {
			sb.append(arr[i]).append(" ");
		}
		System.out.println(sb);
	}
}
