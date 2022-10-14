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
        public Pair(int _r, int _c) { r = _r; c = _c; }
    }

    public class Class1
    {
        static ArrayList map = new ArrayList();
        static int[,] mark = new int[30, 30];
        static int[] dr = { -1, 0, 1, 0 };
        static int[] dc = { 0, 1, 0, -1 };
        static ArrayList answer = new ArrayList();
        static int N;

        static void bfs(int r, int c, int cnt)
        {
            Queue q = new Queue();
            mark[r, c] = cnt;
            q.Enqueue(new Pair(r, c));
            int numberOfHouse = 1;

            while(q.Count != 0)
            {
                Pair front = (Pair)q.Dequeue();
                int nr = front.r;
                int nc = front.c;

                for(int i = 0; i < 4; i++)
                {
                    int nnr = nr + dr[i];
                    int nnc = nc + dc[i];
                    if (nnr < 0 || nnr >= N || nnc < 0 || nnc >= N) continue;
                    if (mark[nnr, nnc] > 0 || ((string)map[nnr])[nnc] == '0') continue;
                    mark[nnr, nnc] = cnt;
                    q.Enqueue(new Pair(nnr, nnc));
                    numberOfHouse++;
                }
            }
            answer.Add(numberOfHouse);
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            N = int.Parse(sr.ReadLine());
            for(int i = 0; i < N; i++)
            {
                string tmp = sr.ReadLine();
                map.Add(tmp);
            }

            int cnt = 1;
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if(((string)map[i])[j] == '1' && mark[i,j] == 0)
                    {
                        bfs(i, j, cnt);
                        cnt++;
                    }
                }
            }

            answer.Sort();
            WriteLine(cnt - 1);
            foreach (var x in answer) WriteLine(x);
        }
    }
}
