using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {
        static double epsilon = 0.000001;
        static double x, y, c;

        static double Cal(double mid)
        {
            double h1 = Math.Sqrt(x * x - mid * mid);
            double h2 = Math.Sqrt(y * y - mid * mid);
            return (h1 * h2) / (h1 + h2);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            x = Double.Parse(_s[0]);
            y = Double.Parse(_s[1]);
            c = Double.Parse(_s[2]);

            double low = 0;
            double high = Math.Min(x, y);
            double result = 0;

            while (high - low > epsilon)
            {
                // w1 + w2
                double mid = (low + high) / 2.0;

                if (Cal(mid) >= c)
                {
                    result = mid;
                    low = mid;
                }
                else
                    high = mid;
            }
            String s = String.Format("{0:0.000}", result);
            Write(s);
        }

    }
}
