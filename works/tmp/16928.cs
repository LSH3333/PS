using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Pair
    {
        public int cur, cnt;
        public Pair(int _cur, int _cnt) { cur = _cur; cnt = _cnt; }
    }

    class Program
    {
        static int n, m;
        static bool[] mark = new bool[101];
        static int[] moveTo = new int[101];
        static int answer;

        static void bfs()
        {
            Queue q = new Queue();
            q.Enqueue(new Pair(1, 0));

            while (q.Count != 0)
            {
                Pair top = (Pair)q.Dequeue();
                int cur = top.cur;
                int cnt = top.cnt;

                if (cur == 100) { answer = cnt; break; }

                for (int i = 1; i <= 6; i++)
                {
                    int ncur = cur + i;
                    if (ncur > 100 || mark[ncur]) continue;
                    if (moveTo[ncur] != 0)
                    {
                        ncur = moveTo[ncur];
                        mark[ncur] = true;
                        q.Enqueue(new Pair(ncur, cnt + 1));
                    }
                    else
                    {
                        mark[ncur] = true;
                        q.Enqueue(new Pair(ncur, cnt + 1));
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            n = int.Parse(_s[0]);
            m = int.Parse(_s[1]);
            for (int i = 0; i < n + m; i++)
            {
                _s = sr.ReadLine().Split(' ');
                moveTo[int.Parse(_s[0])] = int.Parse(_s[1]);
            }

            bfs();
            Write(answer);
        }

    }
}
