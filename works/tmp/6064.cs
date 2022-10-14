using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int t = int.Parse(sr.ReadLine());
            while (t-- > 0)
            {
                string[] _s = sr.ReadLine().Split(' ');
                int M = int.Parse(_s[0]);
                int N = int.Parse(_s[1]);
                int x = int.Parse(_s[2]);
                int y = int.Parse(_s[3]);

                int big, small, bigVal, smallVal;
                if (M < N) { big = N; bigVal = y; small = M; smallVal = x; }
                else { big = M; bigVal = x; small = N; smallVal = y; }

                int temp = smallVal;
                int sub = big - small;
                int cnt = 0;
                bool found = false;

                while (true)
                {
                    if (temp == bigVal) { found = true; break; }

                    if (temp - sub <= 0)
                    {
                        int subTmp = temp - sub;
                        temp = big - (subTmp * -1);
                    }
                    else temp -= sub;

                    if (temp == smallVal) break;

                    cnt++;
                }

                if (!found) WriteLine(-1);
                else WriteLine((small * cnt) + smallVal);
            }
        }

    }
}
