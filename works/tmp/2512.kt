import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var arr = IntArray(10001)
    var N = br.readLine().toInt()
    var maxVal = 0
    val _s = br.readLine().split(' ')
    for(i in 0 until N)
    {
        arr[i] = _s[i].toInt()
        if(arr[i] > maxVal) maxVal = arr[i]
    }
    var M = br.readLine().toInt()

    var left = 0; var right = maxVal; var answer = 0
    while(left <= right)
    {
        var mid = (left + right) / 2
        var sum = 0
        for(i in 0 until N)
        {
            if(arr[i] > mid) sum += mid
            else sum += arr[i]
        }
        if(sum <= M)
        {
            left = mid + 1
            answer = mid
        }
        else
        {
            right = mid - 1
        }
    }
    print(answer)
}