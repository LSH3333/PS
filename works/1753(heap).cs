using static System.Console;
using System.Text;
using System.Collections;
using System.Collections.Generic;
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

        public class Node
        {
            public int distance;
            public int cur;
            public Node(int _distance, int _cur)
            {
                distance = _distance;
                cur = _cur;
            }
        }

        static int V, E, start;
        static int INF = 2000000000;
        static int qSize = 0;
        static Node[] q = new Node[100000];

        static void enqueue(Node[] arr, Node node)
        {
            int i = 0;
            qSize++;
            i = qSize;
            arr[i] = node;

            while(i > 1 && arr[i/2].distance > arr[i].distance)
            {
                // swap 
                Node tmp = arr[i / 2];
                arr[i / 2] = arr[i];
                arr[i] = tmp;

                i = i / 2;
            }
        }

        static void min_heapify(Node[] arr, int i)
        {
            int smallest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= qSize && arr[left].distance < arr[i].distance) smallest = left;
            if (right <= qSize && arr[right].distance < arr[smallest].distance) smallest = right;

            if(smallest != i)
            {
                Node tmp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = tmp;

                min_heapify(arr, smallest);
            }
        }

        static Node dequeue(Node[] arr)
        {
            Node max = arr[1];
            arr[1] = arr[qSize];
            qSize--;

            min_heapify(arr, 1);
            return max;
        }

        static void Dijkstra(ArrayList d, ArrayList[] graph)
        {
            d[start] = 0;
            enqueue(q, new Node(0, start));

            while(qSize > 0)
            {
                Node top = dequeue(q);
                int distance = top.distance;
                int cur = top.cur;

                if ((int)d[cur] < distance) continue;

                for(int i = 0; i < graph[cur].Count; i++)
                {
                    Pair p = (Pair)graph[cur][i];
                    int next = p.distance;
                    int nextDistance = distance + p.cur;

                    if(nextDistance < (int)d[next])
                    {
                        d[next] = nextDistance;
                        enqueue(q, new Node(nextDistance, next));
                    }
                }
            }            
        }

        public static void Main(string[] args)
        {


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
