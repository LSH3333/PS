import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.sqrt

val MAX = 1000010
var p = Array(MAX) {0}

fun FindPrime()
{
    for(i in 2 until MAX) p[i] = i

    var d = sqrt(1000010.0)
    var d_i = d.toInt()
    for(i in 2 until d_i)
    {
        if(p[i] == 0) continue
        for(j in i*i until MAX step i) p[j] = 0
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    val sb = StringBuilder()

    val n = sc.nextInt()
    val m = sc.nextInt()

    FindPrime()
    for(i in n .. m)
    {
        if(p[i] == 0) continue
        sb.append(p[i]).append('\n')
    }
    print(sb)
}