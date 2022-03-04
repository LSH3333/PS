using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static int n;
        static int[,] ans = new int[110, 110];
        static ArrayList[] list;

        static void dfs(int i, ArrayList mark, ArrayList canVisit)
        {
            foreach (int x in list[i])
            {
                if ((bool)mark[x]) continue;
                mark[x] = true;
                canVisit.Add(x);
                dfs(x, mark, canVisit);
            }

        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            n = int.Parse(sr.ReadLine());
            list = new ArrayList[n];
            for (int i = 0; i < n; i++) list[i] = new ArrayList();
            for (int i = 0; i < n; i++)
            {
                string[] _s = sr.ReadLine().Split(' ');
                for (int j = 0; j < n; j++)
                {
                    if (_s[j] == "1") list[i].Add(j);
                }
            }

            for (int i = 0; i < n; i++)
            {
                ArrayList mark = new ArrayList();
                for (int j = 0; j < n; j++) mark.Add(false);
                ArrayList canVisit = new ArrayList();
                dfs(i, mark, canVisit);
                foreach (int j in canVisit) ans[i, j] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Write(ans[i, j] + " ");
                }
                WriteLine();
            }
        }

    }
}
