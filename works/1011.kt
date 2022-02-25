import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun dfs(distance:Long, moved:Long, cnt:Long): Long
{
    if(distance == 0L) return cnt

    for(move in moved+1 downTo moved-1)
    {
        if(move <= 0) continue
        var sum = (move * (move + 1)) / 2
        if(sum <= distance) return dfs(distance-move, move, cnt+1)
    }
    return 0
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var t = br.readLine().toInt()

    while(t-- > 0)
    {
        val _s = br.readLine().split(' ')
        var x = _s[0].toInt()
        var y = _s[1].toInt()
        var distance = (y - x).toLong()
        var ans = dfs(distance, 0, 0)
        println(ans)
    }
}