using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Tuple
    {
        public int r, c, time;
        public Tuple(int _r, int _c, int _time) { r = _r; c = _c; time = _time; }
    }

    class Program
    {
        static int n, k;
        static bool[,] mark = new bool[2, 200010];
        static string[] arr = new string[2];

        static bool bfs()
        {
            Queue q = new Queue();
            q.Enqueue(new Tuple(0, 0, 0));

            while (q.Count != 0)
            {
                Tuple top = (Tuple)q.Dequeue();
                int r = top.r;
                int c = top.c;
                int time = top.time;

                if (c >= n) return true;
                mark[r, c] = true;

                if (c + 1 >= time + 1 && c + 1 >= n) return true;
                if (c + 1 >= time + 1 && arr[r][c + 1] != '0' && !mark[r, c + 1])
                {
                    mark[r, c + 1] = true;
                    q.Enqueue(new Tuple(r, c + 1, time + 1));
                }

                if (c - 1 >= time + 1 && c - 1 >= 0 && arr[r][c - 1] != '0' && !mark[r, c - 1])
                {
                    mark[r, c - 1] = true;
                    q.Enqueue(new Tuple(r, c - 1, time + 1));
                }

                int nr = r == 0 ? 1 : 0;
                if (c + k >= time + 1 && c + k >= n) return true;
                if (c + k >= time + 1 && arr[nr][c + k] != '0' && !mark[nr, c + k])
                {
                    mark[nr, c + k] = true;
                    q.Enqueue(new Tuple(nr, c + k, time + 1));
                }
            }

            return false;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            n = int.Parse(_s[0]);
            k = int.Parse(_s[1]);

            for (int i = 0; i < 2; i++)
            {
                string s = sr.ReadLine(); arr[i] = s;
            }

            int ans = 0;
            if (bfs()) ans = 1;
            Write(ans);
        }

    }
}
