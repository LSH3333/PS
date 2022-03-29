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
            string[] _s = ReadLine().Split(' ');
            int N = int.Parse(_s[0]); int K = int.Parse(_s[1]);
            int[,] arr = new int[7, 2];
            for (int i = 0; i < N; i++)
            {
                _s = ReadLine().Split(' ');
                int gender = int.Parse(_s[0]);
                int grade = int.Parse(_s[1]);
                arr[grade, gender]++;
            }

            int[] v = new int[5];
            v[0] = arr[1, 0] + arr[1, 1] + arr[2, 0] + arr[2, 1];
            v[1] = arr[3, 0] + arr[4, 0];
            v[2] = arr[3, 1] + arr[4, 1];
            v[3] = arr[5, 0] + arr[6, 0];
            v[4] = arr[5, 1] + arr[6, 1];

            int ans = 0;
            foreach (int x in v)
            {
                ans += x / K;
                if (x % K != 0) ans++;
            }
            Write(ans);
        }

    }
}
