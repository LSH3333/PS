import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Tuple
{
    int r, c, cnt;
    public Tuple(int _r, int _c, int _cnt) { r = _r; c = _c; cnt = _cnt; }
}

public class Main
{
    static int n, r1, c1, r2, c2;
    static boolean[][] mark = new boolean[201][201];
    static int[] dr = {-2, -2, 0, 0, 2, 2};
    static int[] dc = {-1, 1, -2, 2, -1, 1};

    static int bfs()
    {
        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(r1, c1, 0));

        while(!q.isEmpty())
        {
            Tuple top = q.poll();
            int r = top.r;
            int c = top.c;
            int cnt = top.cnt;

            for(int i = 0; i < 6; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(mark[nr][nc]) continue;
                if(nr == r2 && nc == c2) return cnt+1;
                mark[nr][nc] = true;
                q.add(new Tuple(nr, nc, cnt+1));
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        String[] _s = br.readLine().split(" ");
        r1 = Integer.parseInt(_s[0]); c1 = Integer.parseInt(_s[1]);
        r2 = Integer.parseInt(_s[2]); c2 = Integer.parseInt(_s[3]);
        System.out.print(bfs());
    }

}
