import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun CCW(x1:Long, y1:Long, x2:Long, y2:Long, x3:Long, y3:Long): Int
{
    val a = x1*y2 + x2*y3 + x3*y1
    val b = x2*y1 + x3*y2 + x1*y3
    if(a-b > 0) return 1
    return -1
}

fun main()
{
    val sc = Scanner(System.`in`)
    val x1 = sc.nextLong(); var y1 = sc.nextLong()
    val x2 = sc.nextLong(); var y2 = sc.nextLong()
    val x3 = sc.nextLong(); var y3 = sc.nextLong()
    val x4 = sc.nextLong(); var y4 = sc.nextLong()

    val abc = CCW(x1, y1, x2, y2, x3, y3)
    val abd = CCW(x1, y1, x2, y2, x4, y4)

    val dca = CCW(x4, y4, x3, y3, x1, y1)
    val dcb = CCW(x4, y4, x3, y3, x2, y2)

    if(abc*abd < 0 && dca*dcb < 0) print(1)
    else print(0)
}