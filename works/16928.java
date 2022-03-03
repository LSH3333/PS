import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair
{
    int cur, cnt;
    public Pair(int _cur, int _cnt) { cur = _cur; cnt = _cnt; }
}

public class Main
{
    static int n, m;
    static boolean[] mark = new boolean[101];
    static int[] moveTo = new int[101];
    static int answer;

    static void bfs()
    {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(1, 0));

        while(!q.isEmpty())
        {
            Pair top = q.poll();
            int cur = top.cur;
            int cnt = top.cnt;

            if(cur == 100) { answer = cnt; break; }

            for(int i = 1; i <= 6; i++)
            {
                int ncur = cur + i;
                if(ncur > 100 || mark[ncur]) continue;
                if(moveTo[ncur] != 0)
                {
                    ncur = moveTo[ncur];
                    mark[ncur] = true;
                    q.add(new Pair(ncur, cnt+1));
                }
                else
                {
                    mark[ncur] = true;
                    q.add(new Pair(ncur, cnt+1));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        n = Integer.parseInt(_s[0]);
        m = Integer.parseInt(_s[1]);
        for(int i = 0; i < n+m; i++)
        {
            _s = br.readLine().split(" ");
            moveTo[Integer.parseInt(_s[0])] = Integer.parseInt(_s[1]);
        }

        bfs();
        System.out.print(answer);
    }

}
