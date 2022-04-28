import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    val N = _s[0].toInt()
    val L = _s[1].toInt()
    var a = Array(N){0}

    _s = br.readLine().split(' ')
    for(i in 0 until N) a[i] = _s[i].toInt()
    Arrays.sort(a)

    var end = a[0] - 0.5 + L
    var cnt = 1
    for(i in 1 until N)
    {
        if(a[i] + 0.5 <= end) continue
        cnt++
        end = a[i] - 0.5 + L
    }

    print(cnt)

}