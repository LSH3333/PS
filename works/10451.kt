import java.util.*;

// Array 내부에 ArrayList
var edge = Array<ArrayList<Int>> (0) {ArrayList<Int>(0)}
var mark = Array<Boolean>(0){false}
var T = 0
var N = 0

fun dfs(n: Int)
{
    if(mark[n]) return
    mark[n] = true
    // foreach
    edge[n].forEach{
        dfs(it)
    }
}

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    T = sc.nextInt()

    while (T-- > 0)
    {
        N = sc.nextInt()
        sc.nextLine()
        edge = Array<ArrayList<Int>> (N+1) {ArrayList<Int>(0)}
        mark = Array<Boolean>(N+1){false}

        var cnt = 0
        var tmp = sc.nextLine()
        var s_tmp = tmp.split(" ")
        for(i in 1..N)
        {
            val v = s_tmp[i-1].toInt()
            edge[i].add(v)
            edge[v].add(i)
        }

        for(i in 1..N)
        {
            if(mark[i]) continue
            dfs(i)
            cnt++
        }
        System.out.println(cnt)
    }


}