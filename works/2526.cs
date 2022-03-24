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
            int a = int.Parse(_s[0]);
            int b = int.Parse(_s[1]);
            Dictionary<int, int> m = new Dictionary<int, int>();
            int num = a, cnt = 1;

            while (true)
            {
                if (m.ContainsKey(num))
                {
                    Write(m.Count - (m[num] - 1));
                    break;
                }
                m[num] = cnt++;
                num = num * a % b;
            }
        }

    }
}
