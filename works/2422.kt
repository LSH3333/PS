import java.util.*

var N = 0; var M = 0
var v = ArrayList<Int>()
var mark = Array<Boolean>(201){false}
var ans = 0
var bad = Array<Array<Boolean>>(201){Array<Boolean>(201){false} }


fun IsPossible(): Boolean
{
    for(i in 0 until 3)
    {
        for(j in 0 until 3)
        {
            if(i == j) continue
            if(bad[v[i]][v[j]]) return false
        }
    }
    return true
}

fun dfs(idx:Int, depth:Int)
{
    if(depth == 3)
    {
        if(IsPossible()) ans += 1
        return
    }

    for(i in idx..N)
    {
        if(mark[i]) continue
        mark[i] = true
        v.add(i)
        dfs(i, depth+1)
        mark[i] = false
        v.removeAt(v.size-1)
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    N = sc.nextInt(); M = sc.nextInt()
    for(i in 0 until M)
    {
        val a = sc.nextInt()
        val b = sc.nextInt()
        bad[a][b] = true
        bad[b][a] = true
    }
    dfs(1,0)
    print(ans)
}