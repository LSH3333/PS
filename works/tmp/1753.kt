import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Pair(_distance:Int, _cur:Int) : Comparable<Pair>
{
    var distance = _distance
    var cur = _cur
    override fun compareTo(other: Pair): Int = distance - other.distance

}

var V = 0; var E = 0; var start = 0
val INF = 2000000000

fun Dijkstra(graph: Array<ArrayList<Pair>>) : IntArray
{
    val d = IntArray(V+1) { INF }
    d[start] = 0
    val pq = PriorityQueue<Pair>()
    pq.add(Pair(0, start))

    while(!pq.isEmpty())
    {
        val top = pq.poll()
        val distance = top.distance
        val cur = top.cur

        if(d[cur] < distance) continue

        for(i in 0 until graph[cur].size)
        {
            val next = graph[cur][i].distance
            val nextDistance = distance + graph[cur][i].cur

            if(nextDistance < d[next])
            {
                d[next] = nextDistance
                pq.add(Pair(nextDistance, next))
            }
        }
    }
    return d
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    var _s = br.readLine().split(' ')
    V = _s[0].toInt()
    E = _s[1].toInt()
    start = br.readLine().toInt()

    val graph = Array(V+1) { ArrayList<Pair>()}
    for(i in 0 until E)
    {
        _s = br.readLine().split(' ')
        graph[_s[0].toInt()].add(Pair(_s[1].toInt(), _s[2].toInt()))
    }

    val d = Dijkstra(graph)

    for(i in 1 .. V)
    {
        if(d[i] != INF)  sb.append("${d[i]}\n")
        else sb.append("INF\n")
    }

    print(sb.toString())
}