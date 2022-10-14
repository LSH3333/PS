import java.io.BufferedReader
import java.io.InputStreamReader


val arr = Array(3000) { IntArray(3000) }
val answer = arrayOf(0, 0, 0)

fun Cal(n:Int, r:Int, c:Int)
{
    val num = arr[r][c]
    var trigger = true
    for(i in r until r+n)
    {
        for(j in c until c+n)
        {
            if(arr[i][j] != num) { trigger = false; break; }
        }
    }
    if(trigger)
    {
        answer[num+1]++
        return
    }

    for(i in r until r+n step n/3)
    {
        for(j in c until c+n step n/3)
        {
            Cal(n/3, i, j)
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var N = br.readLine().toInt()

    for(i in 0 until N)
    {
        val _s = br.readLine().split(' ')
        for(j in 0 until N)
        {
            arr[i][j] = _s[j].toInt()
        }
    }

    Cal(N, 0, 0)

    for(x in answer) println(x)
}
