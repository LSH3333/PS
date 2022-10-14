using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            long[,] d = new long[100, 2];
            int n = int.Parse(ReadLine());
            d[1, 0] = 0;
            d[1, 1] = 1;

            for(int i = 2; i <= n; i++)
            {
                d[i,0] = d[i - 1, 0] + d[i - 1,1];
                d[i,1] = d[i - 1,0];
            }

            WriteLine(d[n, 0] + d[n, 1]);
        }

    }
}
