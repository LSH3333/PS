using System.Collections;
using System.Collections.Generic;
using static System.Console;
using System.Text;

namespace Project1
{
    public class Class1
    {
        static int N, M;
        static List<int>[] edge = new List<int>[100010];
        static int[] answer = new int[100010];

        static void bfs()
        {
            Queue<int> q = new Queue<int>();           
            q.Enqueue(1);

            while(q.Count != 0)
            {
                int v = (int)q.Dequeue();

                foreach(int x in edge[v])
                {
                    if (answer[x] != 0) continue;
                    answer[x] = v;
                    q.Enqueue(x);
                }
            }
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            for (int i = 0; i < 100010; i++) edge[i] = new List<int>();
            string[] s;

            for(int i = 0; i < n-1; i++)
            {
                int a, b;
                s = ReadLine().Split(' ');
                a = int.Parse(s[0]);
                b = int.Parse(s[1]);
                edge[a].Add(b);
                edge[b].Add(a);
            }

            bfs();

            //for (int i = 2; i <= n; i++)
            //    WriteLine(answer[i]);

            //string str = "";
            //for(int i = 2; i <= n; i++)
            //{
            //    str += answer[i] + "\n";
            //}

            StringBuilder sb = new StringBuilder();
            for(int i = 2; i <= n; i++)
            {
                sb.Append(answer[i]).Append("\n");
            }

            Write(sb);
        }

        
    }
}
