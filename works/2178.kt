import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var map = ArrayList<String>()
var mark = Array<Array<Boolean>>(110){Array<Boolean>(110){false} }
val dr = arrayOf(-1, 0, 1, 0)
val dc = arrayOf(0, 1, 0, -1)
var n = 0; var m = 0; var answer = 200000000

class Pair(_r:Int, _c:Int, _depth:Int)
{
    var r = _r
    var c = _c
    var depth = _depth
}

fun bfs()
{
    val q = LinkedList<Pair>()
    mark[0][0] = true
    q.add(Pair(0, 0, 1))

    while(!q.isEmpty())
    {
        var r = q.peek().r
        var c = q.peek().c
        var depth = q.peek().depth
        q.poll()

        if(r == n-1 && c == m-1)
        {
            answer = Math.min(answer, depth)
            continue
        }

        for(i in 0 until 4)
        {
            var nr = r + dr[i]
            var nc = c + dc[i]
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue
            if(mark[nr][nc] || map[nr][nc] == '0') continue
            mark[nr][nc] = true
            q.add(Pair(nr, nc, depth+1))
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    n = Integer.parseInt(_s[0])
    m = Integer.parseInt(_s[1])
    for(i in 0 until n)
    {
        val str = br.readLine()
        map.add(str)
    }

    bfs()

    print(answer)
}