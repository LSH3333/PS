using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using static System.Console;

namespace ConsoleApp
{
    class Tuple
    {
        public int r, c, cnt;
        public Tuple(int _r, int _c, int _cnt) { r = _r; c = _c; cnt = _cnt; }
    }

    class Program
    {
        static int n, r1, c1, r2, c2;
        static bool[,] mark = new bool[201, 201];
        static int[] dr = { -2, -2, 0, 0, 2, 2 };
        static int[] dc = { -1, 1, -2, 2, -1, 1 };

        static int bfs()
        {
            Queue q = new Queue();
            q.Enqueue(new Tuple(r1, c1, 0));

            while (q.Count != 0)
            {
                Tuple top = (Tuple)q.Dequeue();
                int r = top.r;
                int c = top.c;
                int cnt = top.cnt;

                for (int i = 0; i < 6; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (mark[nr, nc]) continue;
                    if (nr == r2 && nc == c2) return cnt + 1;
                    mark[nr, nc] = true;
                    q.Enqueue(new Tuple(nr, nc, cnt + 1));
                }
            }
            return -1;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            n = int.Parse(sr.ReadLine());
            string[] _s = sr.ReadLine().Split(' ');
            r1 = int.Parse(_s[0]); c1 = int.Parse(_s[1]);
            r2 = int.Parse(_s[2]); c2 = int.Parse(_s[3]);
            Write(bfs());
        }

    }
}
