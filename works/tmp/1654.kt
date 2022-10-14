import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.sqrt



fun main()
{
    val sc = Scanner(System.`in`)
    val len = Array<Long>(10001) {0}
    val K = sc.nextInt()
    val N = sc.nextInt()

    var left = 0L; var right = 0L
    for(i in 0 until K)
    {
        len[i] = sc.nextLong()
        right += len[i]
    }

    var answer = 0L
    while(left <= right)
    {
        var mid = (left + right) / 2
        if(mid == 0L) mid++

        var cnt = 0L
        for(i in 0 until K) cnt += (len[i] / mid)

        if(cnt < N)
        {
            right = mid - 1
        }
        else
        {
            left = mid + 1
            answer = Math.max(mid, answer)
        }
    }
    print(answer)
}