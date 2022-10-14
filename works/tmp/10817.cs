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
            ArrayList v = new ArrayList();
            v.Add(int.Parse(_s[0]));
            v.Add(int.Parse(_s[1]));
            v.Add(int.Parse(_s[2]));
            v.Sort();
            Write(v[1]);
        }

    }
}
