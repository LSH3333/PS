import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Pair(_cur:Int, _cnt:Int)
{
    var cur = _cur
    var cnt = _cnt
}

var n = 0
var m = 0
var mark = Array(101) { false }
var moveTo = Array(101) { 0 }
var answer = 0

fun bfs()
{
    var q = LinkedList<Pair>()
    q.add(Pair(1,0))

    while(!q.isEmpty())
    {
        var top = q.poll()
        var cur = top.cur
        var cnt = top.cnt

        if(cur == 100) { answer = cnt; break }

        for(i in 1 .. 6)
        {
            var ncur = cur + i
            if(ncur > 100 || mark[ncur]) continue
            if(moveTo[ncur] != 0)
            {
                ncur = moveTo[ncur]
                mark[ncur] = true
                q.add( Pair(ncur, cnt+1))
            }
            else
            {
                mark[ncur] = true
                q.add( Pair(ncur, cnt+1))
            }
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    n = _s[0].toInt()
    m = _s[1].toInt()
    for(i in 0 until n+m)
    {
        _s = br.readLine().split(' ')
        moveTo[_s[0].toInt()] = _s[1].toInt()
    }

    bfs()
    print(answer)
}