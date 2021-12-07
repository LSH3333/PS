import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main
{
    static int N, M;
    static ArrayList<Integer>[] edge = new ArrayList[1010];
    static boolean[] mark = new boolean[1010];

    static void dfs(int v)
    {
        if(mark[v]) return;
        mark[v] = true;
        for(int x : edge[v]) dfs(x);
    }

    public static void main(String[] args)
    {
        int cnt = 0;
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 1010; i++) edge[i] = new ArrayList<Integer>();
        N = sc.nextInt(); M = sc.nextInt();

        for(int i = 0; i < M; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edge[a].add(b);
            edge[b].add(a);
        }

        for(int i = 1; i <= N; i++)
        {
            if(mark[i]) continue;
            dfs(i);
            cnt++;
        }
        System.out.print(cnt);
    }
}
