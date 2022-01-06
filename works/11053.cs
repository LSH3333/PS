using System;
using System.Collections;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            int answer = 1;
            int n = int.Parse(ReadLine());
            string[] _s = ReadLine().Split();
            int[] a = new int[1010];
            for (int i = 0; i < n; i++) a[i] = int.Parse(_s[i]);

            int[] d = new int[1010];
            d[0] = 1;
            for (int i = 1; i < n; i++)
            {
                int highest = 0;
                for (int j = 0; j < i; j++)
                {
                    if (a[j] < a[i]) highest = Math.Max(highest, d[j]);
                }
                d[i] = highest + 1;
                answer = Math.Max(answer, d[i]);
            }
            Write(answer);

        }
    }

}
