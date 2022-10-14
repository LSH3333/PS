using System;
using static System.Console;

namespace Project1
{
    public class Class1
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int[] d = new int[100001];
            d[0] = 0;
            d[1] = 1;

            for(int i = 2; i <= n; i++)
            {
                int smallest = 100001;
                int num = 1;
                while(i - num * num >= 0)
                {
                    smallest = Math.Min(smallest, d[i - num * num] + 1);
                    num++;
                }
                d[i] = smallest;
            }

            WriteLine(d[n]);
        }

    }
}
