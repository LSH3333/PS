import java.io.BufferedReader
import java.io.InputStreamReader


class Point(var x: Double, var y: Double, var z: Double)

fun CalDistance(a:Point, b:Point) : Double
{
    return Math.sqrt(Math.pow(a.x - b.x, 2.0) + Math.pow(a.y - b.y, 2.0) + Math.pow(a.z - b.z, 2.0))
}



fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    val _s = br.readLine().split(' ')
    val Ax = _s[0].toDouble()
    val Ay = _s[1].toDouble()
    val Az = _s[2].toDouble()

    val Bx = _s[3].toDouble()
    val By = _s[4].toDouble()
    val Bz = _s[5].toDouble()

    val Cx = _s[6].toDouble()
    val Cy = _s[7].toDouble()
    val Cz = _s[8].toDouble()

    var a = Point(Ax, Ay, Az)
    var b = Point(Bx, By, Bz)
    var c = Point(Cx, Cy, Cz)
    var zero = Point(0.0, 0.0, 0.0)

    var minDistance = CalDistance(zero, Point(10000.0, 10000.0, 10000.0))
    var t = 1000000
    while(t-- > 0)
    {
        val mid = Point((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2)
        var dis = CalDistance(mid, c)
        if(dis < minDistance) minDistance = dis

        var acDis = CalDistance(a, c)
        var bcDis = CalDistance(b, c)

        if(acDis <= bcDis)
            b = mid
        else
            a = mid
    }
    print(minDistance)
}
