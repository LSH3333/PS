using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            long finger = long.Parse(sr.ReadLine());
            long num = long.Parse(sr.ReadLine());
            long ans = 0;
            long goAndReturn = 0;

            if (finger == 1)
            {
                // 왕복할수 있는 횟수
                goAndReturn = num - 1;
                ans = 1 + (8 * goAndReturn);
                ans += 7;
            }
            else if (finger == 5)
            {
                goAndReturn = num;
                ans = 1 + (8 * goAndReturn);
                ans += 3;
            }
            else
            {
                goAndReturn = num / 2;
                ans = 1 + (8 * goAndReturn);
                if (num % 2 == 0)
                {
                    ans += finger - 2;
                }
                else
                {
                    ans += 7 - finger + 1;
                }
            }
            Write(ans);
        }
    }
}
