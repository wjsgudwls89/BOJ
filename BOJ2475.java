package algo_;

import java.util.Scanner;

public class BOJ2475 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[5];
		for (int i = 0; i < 5; i++) {
			arr[i] = sc.nextInt();
		}
		int sum = 0;
		
		for (int i = 0; i < arr.length; i++) {
			int a = arr[i]*arr[i];
			sum+=a;
		}
		System.out.println(sum%10);
	}

}
