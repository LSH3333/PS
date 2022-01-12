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

    var a_tmp = Array(n+1){Array(3){""} }
    var a = Array(n+1){Array(3){0} }
    var d = Array(n+1){Array(3){0} }
    for(i in 0 until n)
    {
        var tmp = br.readLine().split(' ').toTypedArray()
        a_tmp[i] = tmp
    }

    for(i in 0 until n)
    {
        for(j in 0 until 3)
        {
            a[i][j] = a_tmp[i][j].toInt()
        }
    }

    d[0][0] = a[0][0]
    d[0][1] = a[0][1]
    d[0][2] = a[0][2]

    for(i in 1 until n)
    {
        d[i][0] = Math.min(d[i-1][1], d[i-1][2]) + a[i][0];
        d[i][1] = Math.min(d[i-1][0], d[i-1][2]) + a[i][1];
        d[i][2] = Math.min(d[i-1][0], d[i-1][1]) + a[i][2];
    }
    print(Math.min(d[n-1][0], Math.min(d[n-1][1], d[n-1][2])))
}