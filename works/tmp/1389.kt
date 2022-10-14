import java.awt.Point
import java.util.*

var N = 0; var M = 0
var edge = Array<ArrayList<Int>>(0) {ArrayList<Int>(0)}
var mark = Array<Boolean>(101){false}

fun bfs(start:Int): Int
{
    var sum = 0
    var q: Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(start, 0))
    mark[start] = true

    while(!q.isEmpty())
    {
        var nv = q.peek().first
        var depth = q.peek().second
        q.poll()
        sum += depth

        for(x in edge[nv])
        {
            if(mark[x]) continue
            q.add(Pair(x, depth+1))
            mark[x] = true
        }
    }

    return sum
}

fun main()
{
    val sc = Scanner(System.`in`)
    N = sc.nextInt(); M = sc.nextInt()

    edge = Array<ArrayList<Int>>(N+1){ArrayList<Int>(0)}
    for(i in 0 until M)
    {
        var a = sc.nextInt()
        var b = sc.nextInt()
        edge[a].add(b)
        edge[b].add(a)
    }

    var ans = 999999999
    var smallest = 999999999
    for(i in 1..N)
    {
        mark = Array<Boolean>(101){false}
        var res = bfs(i)
        if(res < smallest)
        {
            smallest = res
            ans = i
        }
    }
    print(ans)
}
