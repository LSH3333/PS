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
            List<List<int>> v = new List<List<int>>();
            for (int i = 1; i <= 12; i++)
            {
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    List<int> al = new List<int>();
                    for (int j = 0; j < 31; j++) al.Add(0);
                    v.Add(al);
                }
                else if (i == 4 || i == 6 || i == 9 || i == 11)
                {
                    List<int> al = new List<int>();
                    for (int j = 0; j < 30; j++) al.Add(0);
                    v.Add(al);
                }
                else
                {
                    List<int> al = new List<int>();
                    for (int j = 0; j < 28; j++) al.Add(0);
                    v.Add(al);
                }
            }

            int n = 0;
            for (int i = 0; i < v.Count; i++)
            {
                for (int j = 0; j < v[i].Count; j++)
                {
                    v[i][j] = n;
                    n = (n + 1) % 7;
                }
            }

            string[] _s = ReadLine().Split(' ');
            int x = int.Parse(_s[0]); int y = int.Parse(_s[1]);
            string[] day = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
            WriteLine(day[v[x - 1][y - 1]]);
        }

    }
}
