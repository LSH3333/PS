import java.io.BufferedReader
import java.io.InputStreamReader

fun max(a: Array<Long>): Long
{
    return Math.max(a[0], Math.max(a[1],a[2]))
}

fun main()
{
    var d = Array(100001) { Array<Long>(3){0} }
    var s = Array(2) {Array(100001){0} }

    var sb = StringBuffer()
    val br = BufferedReader(InputStreamReader(System.`in`))
    var t = br.readLine().toInt()

    while(t-- > 0)
    {
        val n = br.readLine().toInt()
        var v = br.readLine().split(' ')
        for(i in 1..n) s[0][i] = v[i-1].toInt()
        v = br.readLine().split(' ')
        for(i in 1..n) s[1][i] = v[i-1].toInt()

        d[0][0] = 0; d[0][1] = 0; d[0][2] = 0
        for(i in 1..n)
        {
            d[i][0] = max(d[i-1])
            d[i][1] = Math.max(d[i-1][0], d[i-1][2]) + s[1][i]
            d[i][2] = Math.max(d[i-1][0], d[i-1][1]) + s[0][i]
        }
        sb.append(max(d[n]))
        sb.append('\n')
    }
    print(sb)
}

