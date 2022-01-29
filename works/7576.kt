import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var map = Array(1010){Array(1010){0} }
var mark = Array(1010){Array(1010){0} }
var N = 0; var M = 0; var answer = 0
var location = ArrayList<Pair>()
var dr = arrayOf(-1, 0, 1, 0)
var dc = arrayOf(0, 1, 0, -1)

class Pair(_r:Int, _c:Int, _depth:Int)
{
    var r = _r
    var c = _c
    var depth = _depth
}

fun bfs()
{
    var q = LinkedList<Pair>()
    for(x in location)
    {
        q.add(Pair(x.r, x.c, 1))
        mark[x.r][x.c] = 1
    }

    while(!q.isEmpty())
    {
        var r = q.peek().r
        var c = q.peek().c
        var depth = q.peek().depth
        q.poll()

        for(i in 0 until 4)
        {
            var nr = r + dr[i]
            var nc = c + dc[i]
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue
            if(map[nr][nc] == -1 || mark[nr][nc] > 0) continue
            mark[nr][nc] = depth+1
            q.add(Pair(nr, nc, depth+1))
            answer = Math.max(answer, depth+1)
        }
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    M = sc.nextInt(); N = sc.nextInt()
    var numOfZero = 0
    for(i in 0 until N)
    {
        for(j in 0 until M)
        {
            map[i][j] = sc.nextInt()
            if(map[i][j] == 1) location.add(Pair(i,j,-1))
            if(map[i][j] == -1) mark[i][j] = -1
            if(map[i][j] == 0) numOfZero++
        }
    }
    if(numOfZero == 0) { print(0); return }

    bfs()

    var success = true
    for(i in 0 until N)
    {
        for(j in 0 until M)
        {
            if(mark[i][j] == 0) { success = false; break }
        }
    }
    if(!success) print(-1)
    else print(answer-1)
}