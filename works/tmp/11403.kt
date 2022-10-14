import java.io.BufferedReader
import java.io.InputStreamReader

var n = 0
var ans = Array(110) {Array(110) {0} }
var list = Array(110){ ArrayList<Int>() }

fun dfs(i:Int, mark:ArrayList<Boolean>, canVisit:ArrayList<Int>)
{
    for(x in list[i])
    {
        if(mark[x]) continue
        mark[x] = true
        canVisit.add(x)
        dfs(x, mark, canVisit)
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    n = br.readLine().toInt()
    for(i in 0 until n)
    {
        var _s = br.readLine().split(' ')
        for(j in 0 until n)
        {
            if(_s[j] == "1") list[i].add(j)
        }
    }

    for(i in 0 until n)
    {
        var mark = ArrayList<Boolean>()
        for(j in 0 until n) mark.add(false)
        var canVisit = ArrayList<Int>()
        dfs(i, mark, canVisit)
        for(j in canVisit) ans[i][j] = 1
    }

    for(i in 0 until n)
    {
        for(j in 0 until n)
        {
            print(ans[i][j])
            print(" ")
        }
        println()
    }

}