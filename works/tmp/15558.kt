import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Tuple(_r:Int, _c:Int, _time:Int)
{
    var r = _r
    var c = _c
    var time = _time
}

var n = 0
var k = 0
var mark = Array(2) { Array(200010) {false} }
var arr = Array(2) {""}

fun bfs(): Boolean
{
    var q = LinkedList<Tuple>()
    q.add(Tuple(0, 0, 0))

    while(!q.isEmpty())
    {
        var top = q.poll()
        var r = top.r
        var c = top.c
        var time = top.time

        if(c >= n) return true
        mark[r][c] = true

        if(c+1 >= time+1 && c+1 >= n) return true
        if(c+1 >= time+1 && arr[r][c+1] != '0' && !mark[r][c+1])
        {
            mark[r][c+1] = true
            q.add(Tuple(r, c+1, time+1))
        }

        if(c-1 >= time+1 && c-1 >= 0 && arr[r][c-1] != '0' && !mark[r][c-1])
        {
            mark[r][c-1] = true
            q.add(Tuple(r, c-1, time+1))
        }

        var nr = 0
        if(r == 0) nr = 1
        if(c+k >= time+1 && c+k >= n) return true
        if(c+k >= time+1 && arr[nr][c+k] != '0' && !mark[nr][c+k])
        {
            mark[nr][c+k] = true
            q.add(Tuple(nr, c+k, time+1))
        }
    }
    return false
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(" ")
    n = _s[0].toInt()
    k = _s[1].toInt()
    for(i in 0 until 2)
    {
        var s = br.readLine()
        arr[i] = s
    }

    var ans = 0
    if(bfs()) ans = 1
    print(ans)
}