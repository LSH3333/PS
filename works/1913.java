import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;

public class Main
{


    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int[] dr = {1, 0, -1, 0};
        int[] dc = {0, 1, 0, -1};
        int N = sc.nextInt();
        int num = sc.nextInt();
        int cnt = N*N;
        int r = 0, c = 0, dir = 0, ansR = 0, ansC = 0;
        int[][] v = new int[N][N];

        while(cnt > 0)
        {
            if(cnt == num) { ansR = r; ansC = c; }
            v[r][c] = cnt;
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N || v[nr][nc] != 0)
            {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }
            r = nr; c = nc;
            cnt--;
        }



        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                sb.append(v[i][j]);
                sb.append(' ');
            } sb.append("\n");
        }
        sb.append(ansR+1); sb.append(' '); sb.append(ansC+1);
        System.out.print(sb);
    }
}
