using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using System.Text;

namespace ConsoleApp
{
    class Pair
    {
        public int first, second;
        public Pair(int _f, int _s) { first = _f; second = _s; }
    }

    class Program
    {
        static int depth = 0;
        static List<Pair> l = new List<Pair>();

        static void Hanoi(int num, int from, int by, int to)
        {
            depth++;
            if (num == 1)
            {
                l.Add(new Pair(from, to));
                return;
            }

            Hanoi(num - 1, from, to, by);
            l.Add(new Pair(from, to));
            Hanoi(num - 1, by, from, to);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();

            int n = int.Parse(sr.ReadLine());
            Hanoi(n, 1, 2, 3);
            WriteLine(depth);
            for (int i = 0; i < l.Count; i++)
            {
                sb.Append(l[i].first).Append(' ').Append(l[i].second).Append('\n');
            }
            Write(sb);
        }

    }
}
