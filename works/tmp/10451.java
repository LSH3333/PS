import java.util.*;
import java.util.Collection;

public class Main
{
    public static int T, N;
    public static boolean[] mark;
    public static ArrayList<Integer>[] edge;

    public static void dfs(int n)
    {
        if(mark[n]) return;
        mark[n] = true;
        for(int x : edge[n]) dfs(x);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while(T-- > 0)
        {
            N = sc.nextInt();
            sc.nextLine();
            edge = new ArrayList[N+1];
            mark = new boolean[N+1];
            for(int i = 0; i < N+1; i++) edge[i] = new ArrayList<Integer>();
            int cnt = 0;
            String tmp = sc.nextLine();
            String[] s_tmp = tmp.split(" ");
            for(int i = 1; i <= N; i++)
            {
                int v = Integer.parseInt(s_tmp[i-1]);
                edge[i].add(v);
                edge[v].add(i);
            }

            for(int i = 1; i <= N; i++)
            {
                if(mark[i]) continue;
                dfs(i);
                cnt++;
            }
            System.out.println(cnt);
        }

    }
}
