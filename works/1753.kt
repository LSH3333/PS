import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Pair(_distance:Int, _cur:Int) : Comparable<Pair>
{
    var distance = _distance
    var cur = _cur
    override fun compareTo(other: Pair): Int = other.distance - distance

}

var V = 0; var E = 0; var start = 0
val INF = 2000000000

fun Dijkstra(d: ArrayList<Int>, graph: Array<ArrayList<Pair>>)
{
    d[start] = 0
    var pq = PriorityQueue<Pair>()
    pq.add(Pair(0, start))

    while(!pq.isEmpty())
    {
        var top = pq.poll()
        var distance = -top.distance
        var cur = top.cur

        if(d[cur] < distance) continue

        for(i in 0 until graph[cur].size)
        {
            var next = graph[cur][i].distance
            var nextDistance = distance + graph[cur][i].cur

            if(nextDistance < d[next])
            {
                d[next] = nextDistance
                pq.add(Pair(-nextDistance, next))
            }
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    V = _s[0].toInt()
    E = _s[1].toInt()
    start = br.readLine().toInt()

    var graph = Array(V+1) { ArrayList<Pair>()}
    for(i in 0 until E)
    {
        _s = br.readLine().split(' ')
        graph[_s[0].toInt()].add(Pair(_s[1].toInt(), _s[2].toInt()))
    }

    var d = ArrayList<Int>()
    for(i in 0 until V+1) d.add(INF)
    Dijkstra(d, graph)

    var ans = ""
    for(i in 1 .. V)
    {
        if(d[i] == INF) ans += "INF\n"
        else { ans += d[i]; ans += '\n' }
    }

    print(ans)
}