import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Tuple(_r:Int, _c:Int, _cnt:Int)
{
    var r = _r
    var c = _c
    var cnt = _cnt
}

var n = 0; var r1 = 0; var c1 = 0; var r2 = 0; var c2 = 0
var mark = Array(201) { Array(201) { false } }
var dr = arrayOf(-2, -2, 0, 0, 2, 2)
var dc = arrayOf(-1, 1, -2, 2, -1, 1)

fun bfs(): Int
{
    var q = LinkedList<Tuple>()
    q.add(Tuple(r1, c1, 0))

    while(!q.isEmpty())
    {
        var top = q.poll()
        var r = top.r
        var c = top.c
        var cnt = top.cnt

        for(i in 0 until 6)
        {
            var nr = r + dr[i]
            var nc = c + dc[i]
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue
            if(mark[nr][nc]) continue
            if(nr == r2 && nc == c2) return cnt+1
            mark[nr][nc] = true
            q.add(Tuple(nr, nc, cnt+1))
        }
    }
    return -1
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    n = br.readLine().toInt()
    var _s = br.readLine().split(" ")
    r1 = _s[0].toInt(); c1 = _s[1].toInt()
    r2 = _s[2].toInt(); c2 = _s[3].toInt()
    print(bfs())
}