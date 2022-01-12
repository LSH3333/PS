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

    d[0] = a[0]
    var answer = d[0]
    for(i in 1 until n)
    {
        var highest = 0
        for(j in 0 until i)
        {
            if(a[j] < a[i]) highest = Math.max(highest, d[j])
        }
        d[i] = highest + a[i]
        answer = Math.max(answer, d[i])
    }
    print(answer)

}