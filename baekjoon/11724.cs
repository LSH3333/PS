using System.Collections;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static int N, M;
        static ArrayList[] edge = new ArrayList[1010];
        static bool[] mark = new bool[1010];

        static void dfs(int v)
        {
            if (mark[v]) return;
            mark[v] = true;
            foreach (int x in edge[v]) dfs(x);
        }

        public static void Main(string[] args)
        {
            for (int i = 0; i < 1010; i++) edge[i] = new ArrayList();
            int cnt = 0;
            string[] s = ReadLine().Split(' ');
            N = int.Parse(s[0]); M = int.Parse(s[1]);

            for(int i = 0; i < M; i++)
            {
                int a, b;
                s = ReadLine().Split(' ');
                a = int.Parse(s[0]); b = int.Parse(s[1]);
                edge[a].Add(b);
                edge[b].Add(a);
            }

            for(int i = 1; i <= N; i++)
            {
                if (mark[i]) continue;
                dfs(i);
                cnt++;
            }
            Write(cnt);
        }
    }
}
