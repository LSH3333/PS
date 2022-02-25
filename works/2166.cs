using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static double[,] cord = new double[10001, 2];

        static double CCW(double x1, double y1, double x2, double y2, double x3, double y3)
        {
            double a = x1 * y2 + x2 * y3 + x3 * y1;
            double b = x2 * y1 + x3 * y2 + x1 * y3;

            return (a - b) / 2;
        }            


        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s;
            int n = int.Parse(sr.ReadLine());
            for(int i = 0; i < n; i++)
            {
                _s = sr.ReadLine().Split();
                cord[i, 0] = double.Parse(_s[0]);
                cord[i, 1] = double.Parse(_s[1]);
            }

            double sum = 0;
            for(int i = 1; i < n - 1; i++)
            {
                sum += CCW(cord[0,0], cord[0,1], cord[i,0], cord[i,1], cord[i + 1,0], cord[i + 1,1]);
            }

            string ans = String.Format("{0:0.0}", Math.Abs(sum));
            Write(ans);
        }
    }
}
