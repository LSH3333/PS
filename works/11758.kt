import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    val x1 = sc.nextInt(); val y1 = sc.nextInt()
    val x2 = sc.nextInt(); val y2 = sc.nextInt()
    val x3 = sc.nextInt(); val y3 = sc.nextInt()

    var a = x1*y2 + x2*y3 + x3*y1
    var b = x2*y1 + x3*y2 + x1*y3
    var cal = a - b

    if(cal == 0) print(0)
    else if(cal > 0) print(1)
    else print(-1)

}