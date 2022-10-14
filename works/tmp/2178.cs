using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    class Pair
    {
        public int r, c, depth;
        public Pair(int _r, int _c, int _depth)
        {
            r = _r;
            c = _c;
            depth = _depth;
        }
    }

    public class Class1
    {
        static ArrayList map = new ArrayList();
        static bool[,] mark = new bool[110,110];
        static int n, m, answer = 2000000000;
        static int[] dr = { -1, 0, 1, 0 };
        static int[] dc = { 0, 1, 0, -1 };

        static void bfs()
        {
            Queue q = new Queue();
            mark[0, 0] = true;
            q.Enqueue(new Pair(0, 0, 1));

            while(q.Count != 0)
            {
                Pair front = (Pair)q.Dequeue();
                int r = front.r;
                int c = front.c;
                int depth = front.depth;

                if(r == n-1 && c == m-1)
                {
                    answer = Math.Min(answer, depth);
                    continue;
                }

                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (mark[nr, nc] || ((string)map[nr])[nc] == '0') continue;
                    mark[nr, nc] = true;
                    q.Enqueue(new Pair(nr, nc, depth + 1));
                }
            }

        }
       
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            n = int.Parse(_s[0]);
            m = int.Parse(_s[1]);
            for(int i = 0; i < n; i++)
            {
                string str = sr.ReadLine();
                map.Add(str);
            }


            bfs();
            Write(answer);
        }
    }
}
