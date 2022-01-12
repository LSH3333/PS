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

            int[,] a = new int[n + 1, 3];
            int[,] d = new int[n + 1, 3];

            for (int i = 0; i < n; i++)
            {
                string[] _s = sr.ReadLine().Split();
                for (int j = 0; j < 3; j++)
                {
                    a[i, j] = int.Parse(_s[j]);
                }
            }

            d[0, 0] = a[0, 0];
            d[0, 1] = a[0, 1];
            d[0, 2] = a[0, 2];

            for (int i = 1; i < n; i++)
            {
                d[i, 0] = Math.Min(d[i - 1, 1], d[i - 1, 2]) + a[i, 0];
                d[i, 1] = Math.Min(d[i - 1, 0], d[i - 1, 2]) + a[i, 1];
                d[i, 2] = Math.Min(d[i - 1, 0], d[i - 1, 1]) + a[i, 2];
            }

            Write(Math.Min(d[n - 1, 0], Math.Min(d[n - 1, 1], d[n - 1, 2])));
        }


    }

}
