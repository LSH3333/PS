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
            int MOD = 9901;
            int[,] d = new int[n + 1, 3];

            d[1, 0] = 1;
            d[1, 1] = 1;
            d[1, 2] = 1;

            for (int i = 2; i <= n; i++)
            {
                d[i, 0] = (d[i - 1, 0] + d[i - 1, 1] + d[i - 1, 2]) % MOD;
                d[i, 1] = (d[i - 1, 0] + d[i - 1, 2]) % MOD;
                d[i, 2] = (d[i - 1, 0] + d[i - 1, 1]) % MOD;
            }

            Write((d[n, 0] + d[n, 1] + d[n, 2]) % MOD);


        }


    }

}
