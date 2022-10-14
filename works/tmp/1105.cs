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
            string n = _s[0];
            string m = _s[1];

            while (n.Length != m.Length)
                n = "0" + n;

            int cnt = 0;
            string _n = n;
            string _m = m;
            for (int i = n.Length - 1; i >= 0; i--)
            {
                if (n[i] == '8' && m[i] == '8')
                {
                    n = n.Substring(0, i) + '9' + n.Substring(i + 1);
                    if (n.CompareTo(m) > 0) cnt++;
                    else { n = _n; m = _m; }
                }
            }
            WriteLine(cnt);
        }


    }





}
