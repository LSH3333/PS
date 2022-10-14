using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using System.Text;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());

            string[] _s = sr.ReadLine().Split(' ');
            int N = int.Parse(_s[0]);
            int M = int.Parse(_s[1]);
            long[] trees = new long[N];

            long left = 0, right = 0;
            _s = sr.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                trees[i] = int.Parse(_s[i]);
                right = Math.Max(right, trees[i]);
            }

            long answer = 0;
            Array.Sort(trees);

            while (left <= right)
            {
                long mid = (left + right) / 2;

                long sum = 0;
                for (int i = 0; i < N; i++)
                {
                    if (trees[i] > mid) sum += (trees[i] - mid);
                }

                if (sum < M)
                {
                    // 절단기 아래로
                    right = mid - 1;
                }
                else
                {
                    // 절단기 위로
                    left = mid + 1;
                    answer = mid;
                }
            }
            Write(answer);
        }

    }
}
