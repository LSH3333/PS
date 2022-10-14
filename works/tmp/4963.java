import java.util.*;
import java.util.Collection;

public class Main
{
    public static int w, h;
    public static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    public static int[] dc = {0, 1, 1, 1, 0, -1, -1, -1};
    public static int[][] arr;
    public static boolean[][] mark;

    public static void dfs(int r, int c)
    {
        if(mark[r][c]) return;

        mark[r][c] = true;
        for(int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if(arr[nr][nc] != 1) continue;
            dfs(nr, nc);
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while(true)
        {
            w = sc.nextInt();
            h = sc.nextInt();
            if(w == 0 && h == 0) return;
            sc.nextLine();
            int ans = 0;
            arr = new int[h][w];
            mark = new boolean[h][w];

            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    arr[i][j] = sc.nextInt();
                }
                sc.nextLine();
            }

            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if(arr[i][j] != 1 || mark[i][j]) continue;
                    dfs(i,j);
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}
