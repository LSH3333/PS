import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    var arr = Array(10) {0}
    for(i in 0 until 10)
    {
        arr[i] = sc.nextInt()
        arr[i] %= 42
    }

    var set = arr.toSet()
    print(set.size)
}