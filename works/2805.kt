import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.sqrt



fun main()
{
    val sc = Scanner(System.`in`)
    var N = sc.nextInt()
    var M = sc.nextInt()
    val trees = LongArray(N) // Array<Long> 사용시 시간초과?

    var left = 0L
    var right = 0L
    for(i in 0 until N)
    {
        trees[i] = sc.nextLong()
        right = Math.max(right, trees[i])
    }

    var answer = 0L
    Arrays.sort(trees)

    while(left <= right)
    {
        var mid = (left + right) / 2

        var sum = 0L
        for(i in 0 until N)
        {
            if(trees[i] > mid) sum += (trees[i] - mid)
        }

        if(sum < M)
        {
            right = mid - 1
        }
        else
        {
            left = mid + 1
            answer = mid
        }
    }
    print(answer)
}
