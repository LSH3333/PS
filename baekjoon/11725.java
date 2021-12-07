import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main
{
    static ArrayList<Integer>[] edge;
    static int[] answer;

    static void bfs()
    {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);

        while(!q.isEmpty())
        {
            int v = q.poll();

            for(int x : edge[v])
            {
                if(answer[x] != 0) continue;
                answer[x] = v;
                q.add(x);
            }
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        edge = new ArrayList[n+1];
        for(int i = 0; i < n+1; i++) edge[i] = new ArrayList<>();
        answer = new int[n+1];

        for(int i = 0; i < n-1; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edge[a].add(b);
            edge[b].add(a);
        }

        bfs();

        for(int i = 2; i <= n; i++)
            System.out.println(answer[i]);
    }
}
