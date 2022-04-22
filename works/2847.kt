import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var arr = Array(101) {0}
    var N = sc.nextInt()
    for(i in 0 until N)
    {
        val num = sc.nextInt()
        arr[i] = num
    }

    var answer = 0
    for(i in N-2 downTo 0)
    {
        if(arr[i] >= arr[i+1])
        {
            var sub = arr[i] - arr[i+1] + 1
            answer += sub
            arr[i] -= sub
        }
    }
    print(answer)
}