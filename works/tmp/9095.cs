using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            int[] d = new int[11];
            d[0] = 0;
            d[1] = 1;
            d[2] = 2;
            d[3] = 4;

            for (int i = 4; i < 11; i++)
                d[i] = d[i - 1] + d[i - 2] + d[i - 3];

            int t = int.Parse(ReadLine());
            while(t-- > 0)
            {
                int n = int.Parse(ReadLine());
                WriteLine(d[n]);
            }
        }

    }
}
