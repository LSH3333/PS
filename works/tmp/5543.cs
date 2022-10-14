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
            int d = int.Parse(ReadLine());
            int e = int.Parse(ReadLine());

            int res1 = Math.Min(a, Math.Min(b, c));
            int res2 = Math.Min(d, e);
            Write(res1 + res2 - 50);

        }

    }
}
