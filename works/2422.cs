using System;
using System.Collections;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static int N, M;
        static ArrayList v = new ArrayList();
        static bool[] mark = new bool[201];
        static int answer = 0;
        static bool[,] bad = new bool[201, 201];

        static bool IsPossible()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i == j) continue;
                    if (bad[(int)v[i], (int)v[j]]) return false;
                }
            }
            return true;
        }

        static void dfs(int idx, int depth)
        {
            if (depth == 3)
            {
                if (IsPossible()) answer++;
                return;
            }

            for (int i = idx; i <= N; i++)
            {
                if (mark[i]) continue;
                mark[i] = true;
                v.Add(i);
                dfs(i, depth + 1);
                mark[i] = false;
                v.RemoveAt(v.Count - 1);
            }
        }

        static void Main(string[] args)
        {
            string[] s = ReadLine().Split();
            N = int.Parse(s[0]); M = int.Parse(s[1]);
            for (int i = 0; i < M; i++)
            {
                s = ReadLine().Split();
                int a = int.Parse(s[0]);
                int b = int.Parse(s[1]);
                bad[a, b] = true;
                bad[b, a] = true;
            }
            dfs(1, 0);
            Write(answer);
        }
    }

}
