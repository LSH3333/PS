import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main
{
    static int N, M, K, a, b;
    static int[][] d = new int[20][20];

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        if(K != 0)
        {
            int R=0, C=0;
            int cnt = 1;
            for(int r = 0; r < N; r++)
            {
                for(int c = 0; c < M; c++)
                {
                    if(cnt++ == K) { R = r; C = c; break;}
                }
            }

            // ~ R,C
            for(int r = 0; r <= R; r++) d[r][0] = 1;
            for(int c = 0; c <= C; c++) d[0][c] = 1;
            for(int r = 1; r <= R; r++)
            {
                for(int c = 1; c <= C; c++)
                {
                    d[r][c] = d[r-1][c] + d[r][c-1];
                }
            }
            a = d[R][C];

            // R,C ~
            for(int r = R; r < N; r++) d[r][C] = 1;
            for(int c = C; c < M; c++) d[R][c] = 1;
            for(int r = R+1; r < N; r++)
            {
                for(int c = C+1; c < M; c++)
                {
                    d[r][c] = d[r-1][c] + d[r][c-1];
                }
            }
            b = d[N-1][M-1];

            System.out.println(a * b);
        }
        else
        {
            for(int r = 0; r < N; r++) d[r][0] = 1;
            for(int c = 0; c < M; c++) d[0][c] = 1;
            for(int r = 1; r < N; r++)
            {
                for(int c = 1; c < M; c++)
                {
                    d[r][c] = d[r-1][c] + d[r][c-1];
                }
            }

            System.out.println(d[N - 1][M - 1]);
        }


    }

}

