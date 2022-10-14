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
            long[] len = new long[10001];
            string[] _s = sr.ReadLine().Split(' ');
            int K = int.Parse(_s[0]);
            int N = int.Parse(_s[1]);

            long left = 0, right = 0;
            for (int i = 0; i < K; i++)
            {
                len[i] = int.Parse(sr.ReadLine());
                right += len[i];
            }

            long answer = 0;
            while (left <= right)
            {
                long mid = (left + right) / 2;
                if (mid == 0) mid++;

                long cnt = 0;
                for (int i = 0; i < K; i++) cnt += (len[i] / mid);

                if (cnt < N)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                    answer = Math.Max(mid, answer);
                }
            }
            Write(answer);
        }

    }
}
