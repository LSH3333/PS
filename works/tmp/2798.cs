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
            string[] _s = sr.ReadLine().Split(' ');
            int n = int.Parse(_s[0]);
            int m = int.Parse(_s[1]);
            _s = sr.ReadLine().Split(' ');
            int ans = 0, ansSub = 99999999;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        int sum = int.Parse(_s[i]) + int.Parse(_s[j]) + int.Parse(_s[k]);
                        if (sum <= m && m - sum < ansSub)
                        {
                            ansSub = m - sum;
                            ans = sum;
                        }
                    }
                }
            }
            Write(ans);
        }

    }
}
