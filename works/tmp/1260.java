import java.util.*;
import java.util.Collection;

public class Main
{
    public static int N, M, V;
    public static ArrayList<Integer>[] edge;
    public static boolean[] mark = new boolean[1001];

    public static void dfs(int n)
    {
        if(mark[n]) return;

        System.out.print(n + " ");
        mark[n] = true;
        for(int x : edge[n]) dfs(x);
    }

    public static void bfs(int n)
    {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(n);
        mark[n] = true;

        while(!q.isEmpty())
        {
            int v = q.poll();
            System.out.print(v + " ");

            for(int x : edge[v])
            {
                if(mark[x]) continue;
                q.add(x);
                mark[x] = true;
            }
        }

    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String tmp = sc.nextLine();
        String[] s_tmp = tmp.split(" ");
        N = Integer.parseInt(s_tmp[0]);
        M = Integer.parseInt(s_tmp[1]);
        V = Integer.parseInt(s_tmp[2]);

        // arrayList 초기화
        edge = new ArrayList[N+1];
        for(int i = 0; i < N+1; i++)
            edge[i] = new ArrayList<Integer>();

        for(int i = 0; i < M; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edge[a].add(b);
            edge[b].add(a);
        }

        for(int i = 1; i <= N; i++)
            Collections.sort(edge[i]);

        dfs(V);
        System.out.println();
        mark = new boolean[1001];
        bfs(V);
    }
}
