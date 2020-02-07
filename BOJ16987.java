import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BOJ16987 {
	static class EGG{
		int h;
		int w;
		public EGG(int h, int w) {
			super();
			this.h = h;
			this.w = w;
		}
	}
	//계란 내구도 무게 정해짐
	//계란으로 계란 칠시 내구도 -= 상대 계란 무게
	// 이게 <0 일시 계란 깨짐 (이떄 카운트)\
	// 내가친 계란의 내구도도 같이 달음.
	static int[] visit;
	static List<EGG> arr = new ArrayList<>();
	static int cnt = 0;
	static int check = 0;
	static int ans = 0;

	public static void DFS(int k,int target) {
		ans = Math.max(ans, cnt);

		//System.out.println(Arrays.toString(visit));
		if(k==visit.length) {
			//System.out.println("hi");
			
			//System.out.println(ans);
			return;
		}

		if(visit[k] == 1) {
			DFS(k+1,k+1);
			return;
		}
		//System.out.println(Arrays.toString(visit));
		if(cnt == visit.length) { ans = cnt;return;}


		//System.out.printf("its k :%d %d\n",k,visit.length-1);

		else {
			for (int i = 0; i < visit.length; i++) {
				if(visit[i] == 0 && i != target) {

					if(arr.get(k).h - arr.get(i).w > 0 && arr.get(i).h - arr.get(k).w>0) {
						arr.get(k).h -= arr.get(i).w;
						arr.get(i).h -= arr.get(k).w;
						DFS(k+1,k+1);
						arr.get(k).h += arr.get(i).w;
						arr.get(i).h += arr.get(k).w;
					}
					else if(arr.get(k).h - arr.get(i).w < 0 && arr.get(i).h - arr.get(k).w<0){
						cnt+=2;
						visit[k] = 1;
						visit[i] = 1;
						DFS(k+1,k+1);
						visit[k] = 0;
						visit[i] = 0;
						cnt-=2;
					}
					else if(arr.get(k).h - arr.get(i).w > 0 && arr.get(i).h - arr.get(k).w<0) {
						cnt++;
						visit[i] = 1;
						arr.get(k).h -= arr.get(i).w;
						DFS(k+1,k+1);
						arr.get(k).h += arr.get(i).w;
						cnt--;
						visit[i] = 0;
					}
					else if(arr.get(k).h - arr.get(i).w < 0 && arr.get(i).h - arr.get(k).w>0) {
						cnt++;
						visit[k] = 1;
						arr.get(i).h -= arr.get(k).w;
						DFS(k+1,k+1);
						arr.get(i).h += arr.get(k).w;
						cnt--;
						visit[k] = 0;
					}
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);

		int n = sc.nextInt();
		visit = new int[n];
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr.add(new EGG(a,b));
		}
		DFS(0,0);
		System.out.println(ans);

	}


}

