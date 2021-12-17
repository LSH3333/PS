using System.Collections;
using System.Collections.Generic;
using static System.Console;
using System.Text;

namespace Project1
{
    public class Class1
    {
        static int N, K;
        static bool[] mark = new bool[100001];
        static int[] dv = { -1, 1, 2 };

        static int bfs()
        {
            Queue<int[]> q = new Queue<int[]>();
            q.Enqueue(new int[] { N, 0 });
            mark[N] = true;

            while (q.Count != 0)
            {
                int[] tmp = q.Dequeue();
                int v = tmp[0]; int depth = tmp[1];

                if (v == K) return depth;

                for (int i = 0; i < 3; i++)
                {
                    int nv;
                    if (i == 2) nv = v * dv[i];
                    else nv = v + dv[i];

                    if (nv < 0 || nv > 100000) continue;
                    if (mark[nv]) continue;
                    q.Enqueue(new int[] { nv, depth + 1 });
                    mark[nv] = true;
                }
            }
            return -1;
        }

        public static void Main(string[] args)
        {
            string[] s = ReadLine().Split();
            N = int.Parse(s[0]); K = int.Parse(s[1]);
            Write(bfs());
        }
    }
}
