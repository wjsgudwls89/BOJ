import java.util.Scanner;

public class BOJ1436 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = "666";
        int cnt = 0;
        int n = sc.nextInt();

        for (int i = 666; i < 5200666; i++) {
            String c = Integer.toString(i);
            if(c.contains(str)) {
                cnt++;

            }

            if(cnt == n) {
                str = c;
                break;
            }
        }
        System.out.println(str);
    }
}
