using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static int CCW(long x1, long y1, long x2, long y2, long x3, long y3)
        {
            long a = x1 * y2 + x2 * y3 + x3 * y1;
            long b = x2 * y1 + x3 * y2 + x1 * y3;

            if (a - b > 0) return 1;
            else return -1;
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split();
            long x1 = long.Parse(_s[0]);
            long y1 = long.Parse(_s[1]);           
            long x2 = long.Parse(_s[2]);
            long y2 = long.Parse(_s[3]);
            _s = sr.ReadLine().Split();
            long x3 = long.Parse(_s[0]);
            long y3 = long.Parse(_s[1]);
            long x4 = long.Parse(_s[2]);
            long y4 = long.Parse(_s[3]);

            int abc = CCW(x1, y1, x2, y2, x3, y3);
            int abd = CCW(x1, y1, x2, y2, x4, y4);

            int dca = CCW(x4, y4, x3, y3, x1, y1);
            int dcb = CCW(x4, y4, x3, y3, x2, y2);

            if (abc * abd < 0 && dca * dcb < 0) Write(1);
            else Write(0);
        }
    }
}
