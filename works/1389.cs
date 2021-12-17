using System.Collections;
using System.Collections.Generic;
using static System.Console;
using System.Text;

namespace Project1
{
    public class Class1
    {
        static int N, M;
        static List<int>[] edge;
        static bool[] mark;

        static int bfs(int start)
        {
            int sum = 0;
            Queue<int[]> q = new Queue<int[]>();
            q.Enqueue(new int[] { start, 0 });
            mark[start] = true;

            while(q.Count != 0)
            {
                int[] tmp = q.Dequeue();
                int nv = tmp[0];
                int depth = tmp[1];
                sum += depth;

                foreach(var x in edge[nv])
                {
                    if (mark[x]) continue;
                    q.Enqueue(new int[] { x, depth + 1 });
                    mark[x] = true;
                }

            }
            return sum;
        }

        public static void Main(string[] args)
        {
            string[] s = ReadLine().Split();
            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
            edge = new List<int>[N + 1];
            for (int i = 0; i < N + 1; i++) edge[i] = new List<int>();           

            for(int i = 0; i < M; i++)
            {
                s = ReadLine().Split();
                int a = int.Parse(s[0]);
                int b = int.Parse(s[1]);
                edge[a].Add(b);
                edge[b].Add(a);         
            }

            int ans = 999999999;
            int smallest = 999999999;
            for(int i = 1; i <= N; i++)
            {
                mark = new bool[101];
                int res = bfs(i);
                if(res < smallest)
                {
                    smallest = res;
                    ans = i;
                }
            }
            Write(ans);
        }
    }
}
