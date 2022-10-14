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
        static int MAX = 1000010;
        static int[] p = new int[MAX];

        static void FindPrime()
        {
            for (int i = 2; i < MAX; i++) p[i] = i;

            for (int i = 2; i * i < MAX; i++)
            {
                if (p[i] == 0) continue;
                for (int j = i * i; j < MAX; j += i) p[j] = 0;
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();
            string[] _s = sr.ReadLine().Split(' ');
            int n = int.Parse(_s[0]);
            int m = int.Parse(_s[1]);

            FindPrime();

            for (int i = n; i <= m; i++)
            {
                if (p[i] == 0) continue;
                sb.Append(p[i]).Append('\n');
            }
            Write(sb);
        }

    }
}
