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
            int a = int.Parse(ReadLine());
            int b = int.Parse(ReadLine());
            int c = int.Parse(ReadLine());
            int res = a * b * c;
            string res_s = res.ToString();
            int[] mark = new int[10];
            for (int i = 0; i < res_s.Length; i++) mark[res_s[i] - '0']++;
            for (int i = 0; i < 10; i++) WriteLine(mark[i]);
        }

    }
}
