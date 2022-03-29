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
            bool[] mark = new bool[2000010];
            bool[] students = new bool[2000010];
            string[] _s = ReadLine().Split(' ');
            int n = int.Parse(_s[0]);
            int c = int.Parse(_s[1]);
            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                int num = int.Parse(ReadLine());
                if (students[num]) continue;
                students[num] = true;
                for (int j = num; j <= c; j += num)
                {
                    if (!mark[j])
                    {
                        cnt++;
                        mark[j] = true;
                    }
                }
            }
            Write(cnt);
        }

    }
}
