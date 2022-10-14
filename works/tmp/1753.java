import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.PriorityQueue;

class Pair implements Comparable<Pair>
{
    int distance, cur;
    public Pair(int _dis, int _cur) { distance = _dis; cur = _cur; }

    @Override
    public int compareTo(Pair target) {
        return this.distance < target.distance ? 1 : -1;
    }
}

public class Main
{
    static int V, E, start;
    static int INF = 2000000000;

    static void Dijkstra(ArrayList<Integer> d, ArrayList<Pair>[] graph)
    {
        d.set(start, 0);
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, start));

        while(!pq.isEmpty())
        {
            Pair top = pq.poll();
            int distance = -top.distance;
            int cur = top.cur;

            if(d.get(cur) < distance) continue;

            for(int i = 0; i < graph[cur].size(); i++)
            {
                int next = graph[cur].get(i).distance;
                int nextDistance = distance + graph[cur].get(i).cur;

                if(nextDistance < d.get(next))
                {
                    d.set(next, nextDistance);
                    pq.add(new Pair(-nextDistance, next));
                }
            }
        }


    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] _s = br.readLine().split(" ");
        V = Integer.parseInt(_s[0]);
        E = Integer.parseInt(_s[1]);
        start = Integer.parseInt(br.readLine());

        ArrayList<Pair>[] graph = new ArrayList[V+1];
        for(int i = 0; i < V+1; i++) graph[i] = new ArrayList<>();
        for(int i = 0; i < E; i++)
        {
            _s = br.readLine().split(" ");
            graph[Integer.parseInt(_s[0])].add(new Pair(Integer.parseInt(_s[1]), Integer.parseInt(_s[2])));
        }

        ArrayList<Integer> d = new ArrayList<>();
        for(int i = 0; i < V+1; i++) d.add(INF);
        Dijkstra(d, graph);

        for(int i = 1; i <= V; i++)
        {
            if(d.get(i) == INF) System.out.println("INF");
            else System.out.println(d.get(i));
        }
    }


}
