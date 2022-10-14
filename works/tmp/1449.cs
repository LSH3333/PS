using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            int N = int.Parse(_s[0]);
            int L = int.Parse(_s[1]);
            int[] a = new int[N];
            _s = sr.ReadLine().Split(' ');

            for (int i = 0; i < N; i++) a[i] = int.Parse(_s[i]);
            Array.Sort(a);

            double end = a[0] - 0.5 + L;
            int cnt = 1;
            for(int i = 1; i < N; i++)
            {
                if (a[i] + 0.5 <= end) continue;
                cnt++;
                end = a[i] - 0.5 + L;
            }
            WriteLine(cnt);
        }

    }
}
