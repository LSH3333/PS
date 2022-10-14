import java.awt.Point
import java.util.*

var N = 0; var K = 0
var mark = Array<Boolean>(100001){false}
val dv: Array<Int> = arrayOf(-1, 1, 2)

fun bfs(): Int
{
    var q: Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(N, 0))
    mark[N] = true

    while(!q.isEmpty())
    {
        var v = q.peek().first
        var depth = q.peek().second
        q.poll()

        if(v == K) return depth

        for(i in 0 until 3)
        {
            var nv:Int
            if(i == 2) nv = v * dv[i]
            else nv = v + dv[i]

            if(nv < 0 || nv > 100000) continue
            if(mark[nv]) continue;
            q.add(Pair(nv, depth+1))
            mark[nv] = true
        }
    }
    return -1
}

fun main()
{
    val sc = Scanner(System.`in`)
    N = sc.nextInt(); K = sc.nextInt()
    print(bfs())
}