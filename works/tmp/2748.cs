using System;
using static System.Console;
namespace ConsoleApp
{
    class Program
    {
        static long[] d = new long[100];

        static long dp(int n)
        {
            if (n <= 1) return n;
            if (d[n] > 0) return d[n];

            d[n] = dp(n - 1) + dp(n - 2);
            return d[n];
        }

        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());

            WriteLine(dp(n));
        }
    }

}
