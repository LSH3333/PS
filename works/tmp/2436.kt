import java.io.BufferedReader
import java.io.InputStreamReader

fun GCD(a:Long, b:Long): Long
{
    if(b == 0L) return a
    return GCD(b, a%b)
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    val _s = br.readLine().split(' ')
    var gcd = _s[0].toLong()
    var lcm = _s[1].toLong()
    var a = 0L
    var b = 0L

    lcm /= gcd
    var i = 0L
    while(true)
    {
        i++
        if(i*i > lcm) break
        if(lcm % i != 0L) continue
        val a_tmp = i
        val b_tmp = lcm / i

        if(GCD(a_tmp, b_tmp) == 1L)
        {
            a = a_tmp
            b = b_tmp
        }
    }
    val _a = a * gcd
    val _b = b * gcd
    print("$_a $_b")
}