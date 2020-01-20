import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ3474 {
    public static void main(String[] args)  throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer((br.readLine()));
        int time = Integer.parseInt(st.nextToken());
        int count;
        for (int tc = 0; tc < time; tc++) {
            count = 0;
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            for (int k =5 ; k <= n ; k*=5){
                count += n/k;
            }
            System.out.println(count);
        }
    }
}
