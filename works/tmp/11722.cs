using System;
using System.Collections;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int n = int.Parse(sr.ReadLine());
            string[] _s = sr.ReadLine().Split();
            int[] a = new int[n + 1];
            int[] d = new int[n + 1];
            for (int i = 0; i < n; i++) a[i] = int.Parse(_s[i]);

            d[0] = 1;
            int answer = 1;
            for (int i = 1; i < n; i++)
            {
                int highest = 1;
                for (int j = 0; j < i; j++)
                {
                    if (a[j] > a[i]) highest = Math.Max(highest, d[j] + 1);
                }
                d[i] = highest;
                answer = Math.Max(answer, d[i]);
            }

            Write(answer);
        }
    }

}
