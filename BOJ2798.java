package algorithm;

import java.util.Scanner;

public class BOJ2798 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int[] arr = new int[100];
		int n = sc.nextInt();
		int m = sc.nextInt();
		int max = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					if(arr[i] + arr[j] + arr [k] > max && arr[i] + 
							arr[j] + arr [k] <= m) {
						max = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
		System.out.println(max);
		
	    
		

	}

}
