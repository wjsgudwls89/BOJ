package algo_;

import java.util.Scanner;

public class BOJ2490 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[][] arr = new int[3][4];

		for (int i = 0; i < 3; i++) {
			int zcnt = 0;
			for (int j = 0; j < 4; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == 0) {
					zcnt++;
				}
			}
			if (zcnt == 0) {
				System.out.println("E");
			} else if (zcnt == 1) {
				System.out.println("A");
			} else if (zcnt == 2) {
				System.out.println("B");
			} else if (zcnt == 3) {
				System.out.println("C");
			} else if (zcnt == 4) {
				System.out.println("D");
			}
		}
	}

}
