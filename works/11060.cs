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

            if (n == 1) { Write(0); return; }

            d[0] = 0;
            for (int i = 1; i < n; i++)
            {
                int lowest = 2000000000;
                bool trigger = false;
                for (int j = 0; j < i; j++)
                {
                    if (j + a[j] >= i) { lowest = Math.Min(lowest, d[j] + 1); trigger = true; }
                }
                if (!trigger) { Write(-1); return; }
                d[i] = lowest;
            }

            Write(d[n - 1]);
        }
    }

}
