import java.util.*;

var N = 0
var M = 0
var V = 0
var edge = Array<ArrayList<Int>>(0) {ArrayList<Int>(0)}
var mark = Array<Boolean>(0){false}

fun dfs(n: Int)
{
    if(mark[n]) return
    print("$n ")
    mark[n] = true
    edge[n].forEach{
        dfs(it)
    }
}

fun bfs(n: Int)
{
    val q: Queue<Int>
    q = LinkedList()
    q.add(n)
    mark[n] = true
    while(!q.isEmpty())
    {
        val v = q.poll()
        print("$v ")
        edge[v].forEach{
            if(!mark[it])
            {
                q.add(it)
                mark[it] = true
            }
        }
    }

}

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    var tmp = sc.nextLine()
    var s_tmp = tmp.split(" ")
    N = s_tmp[0].toInt()
    M = s_tmp[1].toInt()
    V = s_tmp[2].toInt()

    edge = Array<ArrayList<Int>>(N+1){ArrayList<Int>(0)}
    mark = Array<Boolean>(N+1){false}

    for(i in 0 until M)
    {
        val a = sc.nextInt()
        val b = sc.nextInt()
        edge[a].add(b)
        edge[b].add(a)
    }

    for(i in 1..N) edge[i].sort()
//    for(i in 1..N)
//    {
//        edge[i].forEach{
//            print("$it ")
//        }
//        println()
//    }
//    println()

    dfs(V)
    println()
    mark = Array<Boolean>(N+1){false}
    bfs(V)
}