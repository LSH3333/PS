import java.awt.Point
import java.util.*

var N = 0; var M = 0; var ans = 0
var arr = Array<Array<Int>>(51){Array<Int>(51){0} }
var mark = Array<Array<Int>>(51){Array<Int>(51){0} }
val dr = arrayOf(-1, -1, 0, 1, 1, 1, 0, -1)
val dc = arrayOf(0, 1, 1, 1, 0, -1, -1, -1)


fun bfs(r:Int, c:Int)
{
    var q: Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(r,c))
    mark[r][c] = 1

    while(!q.isEmpty())
    {
        var nr = q.peek().first
        var nc = q.peek().second
        q.poll()

        if(arr[nr][nc] == 1)
        {
            if(mark[nr][nc]-1 > ans) ans = mark[nr][nc]-1;
            break;
        }

        for(i in 0 until 8)
        {
            var nnr = nr + dr[i]
            var nnc = nc + dc[i]

            if((nnr < 0) || (nnr >= N) || (nnc < 0) || (nnc > M)) continue
            if(mark[nnr][nnc] != 0) continue
            q.add(Pair(nnr,nnc))
            mark[nnr][nnc] = mark[nr][nc] + 1
        }
    }

}

fun main()
{
    val sc = Scanner(System.`in`)
    N = sc.nextInt(); M = sc.nextInt()
    for(i in 0 until N)
    {
        for(j in 0 until M)
        {
            arr[i][j] = sc.nextInt();
        }
    }

    for(i in 0 until N)
    {
        for(j in 0 until M)
        {
            if(arr[i][j] == 1) continue
            mark = Array<Array<Int>>(N+1){Array<Int>(M+1){0} }
            bfs(i,j)
        }
    }

    print(ans)
}