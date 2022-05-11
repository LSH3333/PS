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
        static int[,] arr = new int[3000, 3000];
        static int[] answer = new int[3];

        static void Cal(int n, int r, int c)
        {
            int num = arr[r, c];
            bool trigger = true;
            for (int i = r; i < r + n; i++)
            {
                for (int j = c; j < c + n; j++)
                {
                    if (arr[i, j] != num) { trigger = false; break; }
                }
            }
            // 한가지 숫자로만 채워져 있음
            if (trigger)
            {
                answer[num + 1]++;
                return;
            }

            for (int i = r; i < r + n; i += n / 3)
            {
                for (int j = c; j < c + n; j += n / 3)
                {
                    Cal(n / 3, i, j);
                }
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            int N = int.Parse(sr.ReadLine());

            string[] _s;
            for (int i = 0; i < N; i++)
            {
                _s = sr.ReadLine().Split(" ");
                for (int j = 0; j < N; j++)
                {
                    arr[i, j] = int.Parse(_s[j]);
                }
            }

            Cal(N, 0, 0);

            foreach (int x in answer) WriteLine(x);
        }

    }
}
