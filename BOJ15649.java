import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ15649 {
    static int n, m;
    static int visit[] = new int[9];
    static int arr[] = new int[9];
    public static StringBuilder sb = new StringBuilder(); // 이걸쓰면 시간대폭 줄일 수 있음
    public  static void DFS(int depth){
        if(depth ==m){
            for (int i = 1; i <=m ; i++) {
                sb.append(arr[i]).append(' ');
            }
            sb.append('\n');
            return;
        }
        else{
            for (int i = 1; i <= n ; i++) {
                if(visit[i] == 0){
                    arr[depth+1] = i;
                    visit[i] = 1;
                    DFS(depth+1);
                    visit[i] = 0;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer((br.readLine()));
        //이부분은 외우는게 좋을듯하다.
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        DFS(0);
        System.out.println(sb);

    }

}
