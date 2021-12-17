import java.awt.*;
import java.nio.charset.StandardCharsets;
import java.util.*;


public class Main
{
    static int N, K;
    static boolean[] mark = new boolean[100001];
    static int[] dv = {-1, 1, 2};

    static int bfs()
    {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(N, 0));
        mark[N] = true;

        while(!q.isEmpty())
        {
            int v = q.peek().x;
            int depth = q.peek().y;
            q.poll();

            if(v == K) return depth;

            for(int i = 0;i < 3; i++)
            {
                int nv;
                if(i == 2) nv = v * dv[i];
                else nv = v + dv[i];

                if(nv < 0 || nv > 100000) continue;
                if(mark[nv]) continue;
                q.add(new Point(nv, depth+1));
                mark[nv] = true;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); K = sc.nextInt();

        System.out.print(bfs());
    }
}
