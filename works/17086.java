import java.awt.*;
import java.nio.charset.StandardCharsets;
import java.util.*;


public class Main
{
    static int N, M, ans;
    static int[][] arr = new int[55][55];
    static int[][] mark;
    static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc =  {0, 1, 1, 1, 0, -1, -1, -1};

    static void bfs(int r, int c)
    {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(r,c));
        mark[r][c] = 1;

        while(!q.isEmpty())
        {
            int nr = q.peek().x;
            int nc = q.peek().y;
            q.poll();

            if(arr[nr][nc] == 1)
            {
                if(mark[nr][nc]-1 > ans) ans = mark[nr][nc]-1;
                break;
            }

            for(int i = 0; i < 8; i++)
            {
                int nnr = nr + dr[i];
                int nnc = nc + dc[i];

                if((nnr < 0) || (nnr >= N) || (nnc < 0) || (nnc > M)) continue;
                if(mark[nnr][nnc] != 0) continue;
                q.add(new Point(nnr,nnc));
                mark[nnr][nnc] = mark[nr][nc] + 1;
            }
        }

    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                arr[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(arr[i][j] == 1) continue;
                mark = new int[N+1][M+1];
                bfs(i,j);
            }
        }
        System.out.print(ans);
    }
}
