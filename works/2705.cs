using System;
using System.Collections;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] d = new int[1010];
            d[1] = 1;
            d[2] = 2;
            for (int i = 1; i <= 1000; i++)
            {
                int sum = 0;
                for (int j = 1; j <= i / 2; j++) sum += d[j];
                d[i] = sum + 1;
            }
            int t = int.Parse(ReadLine());
            while (t-- > 0)
            {
                int n = int.Parse(ReadLine());
                WriteLine(d[n]);
            }
        }
    }

}
