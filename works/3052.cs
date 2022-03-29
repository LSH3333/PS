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
            int[] arr = new int[10];
            for (int i = 0; i < 10; i++)
            {
                arr[i] = int.Parse(ReadLine());
                arr[i] %= 42;
            }
            HashSet<int> set = new HashSet<int>(arr);
            Write(set.Count);

        }

    }
}
