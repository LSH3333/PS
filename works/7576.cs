using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Pair
    {
        public int r;
        public int c;
        public int depth;
        public Pair(int _r, int _c) { r = _r; c = _c; }
        public Pair(int _r, int _c, int _depth)
        {
            r = _r;
            c = _c;
            depth = _depth;
        }
    }

    public class Class1
    {
        static int[,] map = new int[1010, 1010];
        static int[,] mark = new int[1010, 1010];
        static int N, M, answer;
        static ArrayList location = new ArrayList();
        static int[] dr = { -1, 0, 1, 0 };
        static int[] dc = { 0, 1, 0, -1 };

        static void bfs()
        {
            Queue q = new Queue();
            foreach(var x in location)
            {
                Pair pair = (Pair)x;
                q.Enqueue(new Pair(pair.r, pair.c, 1));
                mark[pair.r, pair.c] = 1;
            }

            while(q.Count != 0)
            {
                Pair front = (Pair)q.Dequeue();
                int r = front.r;
                int c = front.c;
                int depth = front.depth;

                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if (map[nr, nc] == -1 || mark[nr, nc] > 0) continue;
                    mark[nr, nc] = depth + 1;
                    q.Enqueue(new Pair(nr, nc, depth + 1));
                    answer = Math.Max(answer, depth + 1);
                }
            }
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            string[] _s = sr.ReadLine().Split(' ');
            M = int.Parse(_s[0]); N = int.Parse(_s[1]);
            int numOfZero = 0;
            for(int i = 0; i < N; i++)
            {
                _s = sr.ReadLine().Split(' ');
                for(int j = 0; j < M; j++)
                {
                    map[i, j] = int.Parse(_s[j]);
                    if (map[i, j] == 1) location.Add(new Pair(i, j));
                    if (map[i, j] == -1) mark[i, j] = -1;
                    if (map[i, j] == 0) numOfZero++;
                }
            }
            if(numOfZero == 0) { Write(0); return; }

            bfs();

            bool success = true;
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < M; j++)
                {
                    if(mark[i,j] == 0) { success = false; break; }
                }
            }

            if (!success) Write(-1);
            else Write(answer - 1);
        }
    }
}
