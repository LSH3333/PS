using System;
using System.Collections.Generic;
using System.Collections;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        public static int N, M, V;
        public static List<int>[] edge;
        public static bool[] mark = new bool[1001];

        public static void dfs(int n)
        {
            if (mark[n]) return;
            Write(n + " ");
            mark[n] = true;
            foreach (var x in edge[n])
                dfs(x);
        }

        public static void bfs(int n)
        {
            Queue<int> q = new Queue<int>();
            q.Enqueue(n);
            mark[n] = true;

            while(q.Count != 0)
            {
                int v = q.Dequeue();
                Write(v + " ");

                foreach(var x in edge[v])
                {
                    if (mark[x]) continue;
                    q.Enqueue(x);
                    mark[x] = true;
                }
            }
        }

        static void Main(string[] args)
        {
            String temp = ReadLine();
            String[] str_temp = temp.Split(' ');
            N = int.Parse(str_temp[0]);
            M = int.Parse(str_temp[1]);
            V = int.Parse(str_temp[2]);

            edge = new List<int>[N+1];
            for (int i = 0; i < N + 1; i++)
                edge[i] = new List<int>();

            for(int i = 0; i < M; i++)
            {
                int a, b;
                temp = ReadLine();
                str_temp = temp.Split(' ');
                a = int.Parse(str_temp[0]);
                b = int.Parse(str_temp[1]);
                edge[a].Add(b);
                edge[b].Add(a);
            }

            for (int i = 1; i <= N; i++)
                edge[i].Sort();

            dfs(V);
            WriteLine();
            mark = new bool[1001];
            bfs(V);
        }

    }
}
