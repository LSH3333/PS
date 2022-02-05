using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static long Cal(long n, long div)
        {
            long cnt = 0;
            while (n > 0)
            {
                n /= div;
                cnt += n;
            }
            return cnt;
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            long n = long.Parse(_s[0]);
            long m = long.Parse(_s[1]);

            long a = Cal(n, 2) - (Cal(m, 2) + Cal(n - m, 2));
            long b = Cal(n, 5) - (Cal(m, 5) + Cal(n - m, 5));
            Write(Math.Min(a, b));
        }
    }
}
