import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Tuple
{
    int r, c, time;
    public Tuple(int _r, int _c, int _time) {r = _r; c = _c; time = _time;}
}

public class Main
{
    static int n, k;
    static boolean[][] mark = new boolean[2][200010];
    static String[] arr = new String[2];

    static boolean bfs()
    {
        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(0,0,0));

        while(!q.isEmpty())
        {
            Tuple top = q.poll();
            int r = top.r;
            int c = top.c;
            int time = top.time;

            if(c >= n) return true;
            mark[r][c] = true;

            if(c+1 >= time+1 && c+1 >= n) return true;
            if(c+1 >= time+1 && arr[r].charAt(c+1) != '0' && !mark[r][c+1])
            {
                mark[r][c+1] = true;
                q.add(new Tuple(r, c+1, time+1));
            }

            if(c-1 >= time+1 && c-1 >= 0 && arr[r].charAt(c-1) != '0' && !mark[r][c-1])
            {
                mark[r][c-1] = true;
                q.add(new Tuple(r, c-1, time+1));
            }

            int nr = r == 0 ? 1 : 0;
            if(c+k >= time+1 && c+k >= n) return true;
            if(c+k >= time+1 && arr[nr].charAt(c+k) != '0' && !mark[nr][c+k])
            {
                mark[nr][c+k] = true;
                q.add(new Tuple(nr, c+k, time+1));
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        n = Integer.parseInt(_s[0]);
        k = Integer.parseInt(_s[1]);
        for(int i = 0; i < 2; i++)
        {
            String s = br.readLine();
            arr[i] = s;
        }
        int ans;
        if(bfs()) ans = 1;
        else ans = 0;
        System.out.print(ans);
    }

}
