package algo_;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class BOJ1197_최소스패닝트리_전형진 {
	static int union[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt();
		int e = sc.nextInt();
		
		union = new int[v+1];
		for (int i = 1; i <= v; i++) {
			union[i] = i;
		}
		
		ArrayList<POS> list = new ArrayList<>();
		
		for (int i = 0; i < e; i++) {
			list.add(new POS(sc.nextInt(),sc.nextInt(),sc.nextInt()));
		}
		list.sort(new Comparator<POS>() {

			@Override
			public int compare(POS o1, POS o2) {
				return o1.w - o2.w;
			}
		});
		
		long ans = 0;
		for (int i = 0; i < e; i++) {
			int x = list.get(i).a;
			int y = list.get(i).b;
			
			if(findroot(y) != findroot(x)) {
				union[findroot(y)] = union[x];
				ans += list.get(i).w;
			}
		}
		System.out.println(ans);
	}
	public static int findroot(int num) {
		if(num != union[num])
			return union[num] = findroot(union[num]);
		else
			return num;
	}
	
	static class POS {
		int a;
		int b;
		int w;
		public POS(int a, int b, int w) {
			this.a = a;
			this.b = b;
			this.w = w;
		}
		
	}
}  
