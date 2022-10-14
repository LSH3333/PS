using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using System.Text;

namespace ConsoleApp
{
    class Program
    {
        static int N;
        static bool fin = false;

        static void Permutation(int[] line, bool[] mark, List<int> l, int depth, int[] order)
        {
            if (depth == N)
            {
                bool isAnswer = true;
                for (int i = 1; i <= N; i++)
                {
                    int cur = l[i];
                    int taller = order[cur];
                    int cnt = 0;
                    for (int j = 1; j < i; j++)
                    {
                        if (l[j] > l[i]) cnt++;
                    }
                    if (cnt != taller) { isAnswer = false; break; }
                }
                if (isAnswer)
                {
                    for (int i = 1; i <= N; i++) Write(l[i] + " ");
                    fin = true;
                }
                return;
            }

            for (int i = 1; i <= N; i++)
            {
                if (mark[i]) continue;
                mark[i] = true;
                l.Add(line[i]);
                Permutation(line, mark, l, depth + 1, order);
                mark[i] = false;
                l.RemoveAt(l.Count - 1);
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            N = int.Parse(sr.ReadLine());

            int[] line = new int[N + 1];
            for (int i = 1; i <= N; i++) line[i] = i;

            string[] _s = sr.ReadLine().Split(' ');
            int[] order = new int[N + 1];
            for (int i = 1; i <= N; i++) order[i] = int.Parse(_s[i - 1]);

            bool[] mark = new bool[N + 1];

            List<int> l = new List<int>();
            l.Add(0);
            Permutation(line, mark, l, 0, order);
        }

    }
}
