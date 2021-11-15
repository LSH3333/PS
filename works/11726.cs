using System;
using static System.Console;
namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] d = new int[1010];
            int n = int.Parse(ReadLine());

            d[0] = 0;
            d[1] = 1;
            d[2] = 2;

            for (int i = 3; i <= n; i++)
                d[i] = (d[i - 1] + d[i - 2]) % 10007;

            WriteLine(d[n]);
        }
    }

}
