using System;
using static System.Console;
namespace ConsoleApp
{
    class Program
    {
        static int[] d = new int[1000001];

        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());

            d[0] = 0;
            d[1] = 0;

            for (int i = 2; i <= n; i++)
            {
                int num = d[i - 1] + 1;
                if (i % 2 == 0) num = Math.Min(d[i / 2] + 1, num);
                if (i % 3 == 0) num = Math.Min(d[i / 3] + 1, num);
                d[i] = num;
            }

            WriteLine(d[n]);
        }
    }

}
