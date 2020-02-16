import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ7576 {





    public static void main(String[] args) throws IOException {
       // Scanner sc = new Scanner(System.in);
        int m,n;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int cnt = 0;
        boolean flag = false;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        Queue<tom> q = new LinkedList<>();
        int[][] map = new int[n+1][m+1];
        boolean[][] visit = new boolean[n+1][m+1];
        for (int i = 0; i < n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st2.nextToken());
                if(map[i][j] == 1){
                    q.offer(new tom(i,j));
                }
            }
        }
        while(!q.isEmpty()) {
            int qs = q.size();
            while(qs>0) {
                int y = q.peek().y;
                int x = q.peek().x;
                visit[y][x] = true;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visit[ny][nx]
                            && map[ny][nx] == 0) {
                        q.offer(new tom(ny, nx));
                        visit[ny][nx] = true;
                    }
                }
                qs--;
            }
            cnt++;
        }
        flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visit[i][j] && map[i][j] == 0){
                    flag = false;

                }
            }
        }


        if(flag) System.out.println(cnt-1);
        else{
            System.out.println(-1);
        }

    }
    static class tom{
        int y;
        int x;

        public tom(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
