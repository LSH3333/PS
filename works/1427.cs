using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string num = sr.ReadLine();
            int[] v = new int[num.Length];
            for (int i = 0; i < num.Length; i++) v[i] = num[i] - '0';
            Array.Sort(v); Array.Reverse(v);
            foreach (var x in v) Write(x);
            

        }
    }
}
