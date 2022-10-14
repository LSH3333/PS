 using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            long[] d = new long[102];
            d[0] = 0;
            d[1] = 1;
            d[2] = 1;
            d[3] = 1;

            for (int i = 4; i < 101; i++)
            {
                d[i] = d[i - 2] + d[i - 3];
            }

            int t = int.Parse(ReadLine());
            while(t-- > 0)
            {
                int n = int.Parse(ReadLine());
                WriteLine(d[n]);
            }
        }

    }
}
