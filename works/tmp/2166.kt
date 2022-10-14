import java.io.BufferedReader
import java.io.InputStreamReader
import java.nio.Buffer
import java.util.*

fun CCW(x1:Double, y1:Double, x2:Double, y2:Double, x3:Double, y3:Double): Double
{
    val a = x1*y2 + x2*y3 + x3*y1
    val b = x2*y1 + x3*y2 + x1*y3
    return (a-b)/2
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var cord = Array(10001) { Array<Double>(2) {0.0} }
    val n = br.readLine().toInt()
    for(i in 0 until n)
    {
        val _s = br.readLine().split(' ')
        cord[i][0] = _s[0].toDouble()
        cord[i][1] = _s[1].toDouble()
    }

    var sum = 0.0
    for(i in 1 until n-1)
    {
        sum += CCW(cord[0][0], cord[0][1], cord[i][0], cord[i][1], cord[i+1][0], cord[i+1][1]);
    }

    System.out.format("%.1f", Math.abs(sum))
}