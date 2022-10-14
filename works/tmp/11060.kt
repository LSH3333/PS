import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))

    var n = br.readLine().toInt()
    var tmp = br.readLine().split(' ')
    var a = Array<Int>(n+1){0}
    var d = Array<Int>(n+1){0}
    for(i in 0 until n) a[i] = tmp[i].toInt()

    if(n == 1) {print(0); return}

    d[0] = 0
    for(i in 1 until n)
    {
        var lowest = 2000000000
        var trigger = false
        for(j in 0 until i)
        {
            if(j + a[j] >= i) { lowest = Math.min(lowest, d[j]+1); trigger = true}
        }
        if(!trigger) { print(-1); return }
        d[i] = lowest
    }
    print(d[n-1])
}