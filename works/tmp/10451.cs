using System;
using System.Collections.Generic;
using System.Collections;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        public static int T, N;
        public static bool[] mark;
        public static List<int>[] edge;

        public static void dfs(int n)
        {
            if (mark[n]) return;
            mark[n] = true;
            foreach (var x in edge[n]) dfs(x);
        }

        static void Main(string[] args)
        {
            T = int.Parse(ReadLine());
            while(T-- > 0)
            {
                N = int.Parse(ReadLine());
                edge = new List<int>[N + 1];
                mark = new bool[N + 1];
                for (int i = 0; i < N + 1; i++) edge[i] = new List<int>();
                int cnt = 0;

                string tmp = ReadLine();
                string[] s_tmp = tmp.Split(" ");
                for(int i = 1; i <= N; i++)
                {
                    int v = int.Parse(s_tmp[i - 1]);
                    edge[i].Add(v);
                    edge[v].Add(i);
                }

                for(int i = 1; i <= N; i++)
                {
                    if (mark[i]) continue;
                    dfs(i);
                    cnt++;
                }
                WriteLine(cnt);
            }
        }

    }
}
