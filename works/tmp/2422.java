import java.util.*;

public class Main
{
    static int N, M;
    static ArrayList<Integer> v = new ArrayList<>();
    static boolean[] mark = new boolean[201];
    static int answer = 0;
    static boolean[][] bad = new boolean[201][201];

    static boolean IsPossible()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == j) continue;
                if(bad[v.get(i)][v.get(j)]) return false;
            }
        }
        return true;
    }

    static void dfs(int idx, int depth)
    {
        if(depth == 3)
        {
            if(IsPossible()) answer++;
            return;
        }

        for(int i = idx; i <= N; i++)
        {
            if(mark[i]) continue;
            mark[i] = true;
            v.add(i);
            dfs(i, depth+1);
            mark[i] = false;
            v.remove(v.size()-1);
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        for(int i = 0; i < M; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            bad[a][b] = true;
            bad[b][a] = true;
        }
        dfs(1, 0);
        System.out.print(answer);
    }

}
