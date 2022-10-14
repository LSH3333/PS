import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun Cal(n:Long, div:Long): Long
{
    var cnt = 0L
    var _n = n
    while(_n > 0)
    {
        _n /= div
        cnt += _n
    }
    return cnt
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(" ")
    var n = _s[0].toLong()
    var m = _s[1].toLong()

    var a = Cal(n,2) - (Cal(m,2) + Cal(n-m,2))
    var b = Cal(n, 5) - (Cal(m,5) + Cal(n-m, 5))
    print(Math.min(a,b))
}