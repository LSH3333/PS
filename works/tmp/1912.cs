using System;
using System.Collections;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int[] a = new int[100001];
            int[] d = new int[100001];

            string[] _s = ReadLine().Split();
            for (int i = 0; i < n; i++) a[i] = int.Parse(_s[i]);

            d[0] = a[0];
            int answer = d[0];
            for (int i = 1; i < n; i++)
            {
                d[i] = Math.Max(d[i - 1] + a[i], a[i]);
                answer = Math.Max(answer, d[i]);
            }
            Write(answer);
        }
    }

}
