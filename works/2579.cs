using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int[] score = new int[302];
            int[,] d = new int[302, 2];

            for (int i = 1; i <= n; i++)
                score[i] = int.Parse(ReadLine());

            score[0] = 0;
            d[0,0] = 0;
            d[0, 1] = 0;
            d[1, 0] = score[1];
            d[1, 1] = score[1];

            for(int i = 2; i <= n; i++)
            {
                d[i, 0] = d[i - 1, 1] + score[i];
                d[i, 1] = Math.Max(d[i - 2, 0], d[i - 2, 1]) + score[i];
            }

            WriteLine(Math.Max(d[n, 0], d[n, 1]));
        }

    }
}
