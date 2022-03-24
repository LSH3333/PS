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
            int[,] arr = new int[15, 15];
            // 0Ãþ
            for (int i = 1; i < 15; i++) arr[0, i] = i;
            // 1È£
            for (int i = 0; i < 15; i++) arr[i, 1] = 1;

            for (int i = 1; i < 15; i++)
            {
                for (int j = 1; j < 15; j++)
                {
                    arr[i, j] = arr[i - 1, j] + arr[i, j - 1];
                }
            }

            int t = int.Parse(ReadLine());
            while (t-- > 0)
            {
                int n = int.Parse(ReadLine());
                int k = int.Parse(ReadLine());
                WriteLine(arr[n, k]);
            }

        }

    }
}
