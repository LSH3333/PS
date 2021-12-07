import java.util.*

var edge = Array<ArrayList<Int>>(1010) {ArrayList<Int>(0)}
var mark = Array<Boolean>(1010) { false }
var N = 0
var M = 0

fun dfs(v: Int)
{
    if(mark[v]) return
    mark[v] = true
    for(x in edge[v]) dfs(x)
}

fun main()
{
    val sc = Scanner(System.`in`)
    N = sc.nextInt(); M = sc.nextInt()
    var cnt = 0

    for(i in 0 until M)
    {
        var a = sc.nextInt()
        var b = sc.nextInt()
        edge[a].add(b)
        edge[b].add(a)
    }

    for(i in 1..N)
    {
        if(mark[i]) continue
        dfs(i)
        cnt++
    }
    print(cnt)
}

