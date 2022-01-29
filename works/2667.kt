import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var map = ArrayList<String>()
var mark = Array(30){Array(30){0} }
val dr = arrayOf(-1, 0, 1, 0)
val dc = arrayOf(0, 1, 0, -1)
var answer = ArrayList<Int>()
var N = 0

class Pair(_r:Int, _c:Int)
{
    var r = _r
    var c = _c
}

fun bfs(r:Int, c:Int, cnt:Int)
{
    var q = LinkedList<Pair>()
    mark[r][c] = cnt
    q.add(Pair(r,c))
    var numberOfHouse = 1

    while(!q.isEmpty())
    {
        var nr = q.peek().r
        var nc = q.peek().c
        q.poll()

        for(i in 0 until 4)
        {
            var nnr = nr + dr[i]
            var nnc = nc + dc[i]
            if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= N) continue
            if(mark[nnr][nnc] > 0 || map[nnr][nnc] == '0') continue
            mark[nnr][nnc] = cnt
            q.add(Pair(nnr,nnc))
            numberOfHouse++
        }
    }
    answer.add(numberOfHouse)
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = Integer.parseInt(br.readLine())
    for(i in 0 until N)
    {
        val tmp = br.readLine()
        map.add(tmp)
    }

    var cnt = 1
    for(i in 0 until N)
    {
        for(j in 0 until N)
        {
            if(map[i][j] == '1' && mark[i][j] == 0)
            {
                bfs(i, j, cnt)
                cnt++
            }
        }
    }

    answer.sort()
    println(cnt-1)
    for(x in answer) println(x)
}