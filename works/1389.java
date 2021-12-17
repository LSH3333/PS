import java.security.KeyPair;
import java.util.*;
import java.util.Collection;
import java.awt.*;

public class Main
{
    static int N, M;
    static ArrayList<Integer>[] edge;
    static boolean[] mark;

    static int bfs(int start)
    {
        int sum = 0;
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(start, 0));
        mark[start] = true;

        while(!q.isEmpty())
        {
            int nv = q.peek().x;
            int depth = q.peek().y;
            q.poll();
            sum += depth;

            for(int x : edge[nv])
            {
                if(mark[x]) continue;
                q.add(new Point(x, depth+1));
                mark[x] = true;
            }
        }
        return sum;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        edge = new ArrayList[N+1];
        for(int i = 0; i < N+1; i++) edge[i] = new ArrayList<>();

        for(int i = 0; i < M; i++)
        {
            int a, b;
            a = sc.nextInt(); b = sc.nextInt();
            edge[a].add(b);
            edge[b].add(a);
        }

        int ans = 99999999;
        int smallest = 99999999;

        for(int i = 1; i <= N; i++)
        {
            mark = new boolean[101];
            int res = bfs(i);
            if(res < smallest)
            {
                smallest = res;
                ans = i;
            }
        }
        System.out.print(ans);
    }
}
