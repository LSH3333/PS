using static System.Console;
using System.Text;
using System.Collections;
using System.IO;
using System;

namespace Project1
{
    public class Class1
    {
        public class Pair
        {
            public int distance, cur;
            public Pair(int _distance, int _cur)
            {
                distance = _distance;
                cur = _cur;
            }
        }

        public class CMP: IComparer
        {
            int IComparer.Compare(object _x, object _y)
            {
                Pair x = (Pair)_x;
                Pair y = (Pair)_y;
                return x.distance.CompareTo(y.distance);
            }
        }

        static int V, E, start;
        static int INF = 2000000000;
       

        static void Dijkstra(ArrayList d, ArrayList[] graph)
        {
            d[start] = 0;
            ArrayList q = new ArrayList();
            q.Add(new Pair(0, start));

            while (q.Count != 0)
            {
                Pair top = (Pair)q[0];
                q.RemoveAt(0);
                int distance = -top.distance;
                int cur = top.cur;

                if ((int)d[cur] < distance) continue;

                for (int i = 0; i < graph[cur].Count; i++)
                {
                    Pair p = (Pair)graph[cur][i];
                    int next = p.distance;
                    int nextDistance = distance + p.cur;

                    if (nextDistance < (int)d[next])
                    {
                        d[next] = nextDistance;
                        q.Add(new Pair(-nextDistance, next));                       
                        q.Sort(new CMP());
                    }
                }

            }

        }

        public static void Main(string[] args)
        {
            //ArrayList l = new ArrayList();
            //l.Add(new Pair(0, 2));
            //l.Add(new Pair(-3, 2));
            //l.Add(new Pair(-10, 10));
            //l.Sort(new CMP());
            ////foreach(var x in l)
            ////{
            ////    Pair p = (Pair)x;
            ////    WriteLine(p.distance + " " + p.cur);
            ////}

            //while (l.Count > 0)
            //{
            //    Pair p = (Pair)l[0];
            //    l.RemoveAt(0);
            //    WriteLine(p.distance + " " + p.cur);

            //}



            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StringBuilder sb = new StringBuilder();
            string[] _s = sr.ReadLine().Split(' ');
            V = int.Parse(_s[0]);
            E = int.Parse(_s[1]);
            start = int.Parse(sr.ReadLine());

            ArrayList[] graph = new ArrayList[V + 1];
            for (int i = 0; i < V + 1; i++) graph[i] = new ArrayList();
            for (int i = 0; i < E; i++)
            {
                _s = sr.ReadLine().Split(' ');
                graph[int.Parse(_s[0])].Add(new Pair(int.Parse(_s[1]), int.Parse(_s[2])));
            }

            ArrayList d = new ArrayList();
            for (int i = 0; i < V + 1; i++) d.Add(INF);
            Dijkstra(d, graph);

            for (int i = 1; i <= V; i++)
            {
                if ((int)d[i] == INF) sb.Append("INF\n");
                else
                {
                    String tmp = d[i].ToString() + '\n';
                    sb.Append(tmp);
                }
            }
            Write(sb.ToString());
        }
    }
}
