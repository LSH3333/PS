using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        static long GCD(long a, long b)
        {
            if (b == 0) return a;
            return GCD(b, a % b);
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split();
            long gcd = long.Parse(_s[0]);
            long lcm = long.Parse(_s[1]);
            long a = 0, b = 0;

            lcm /= gcd;
            for(long i = 1; i*i <= lcm; i++)
            {
                if (lcm % i != 0) continue;
                long a_tmp = i;
                long b_tmp = lcm / i;

                if(GCD(a_tmp, b_tmp) == 1)
                {
                    a = a_tmp; b = b_tmp;
                }
            }
            Write(a * gcd + " " + b*gcd);
        }
    }
}
