import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun main()
{
    val sc = Scanner(System.`in`)
    val br = BufferedReader(InputStreamReader(System.`in`))

    var n = br.readLine().toInt()
    var v = br.readLine().split(' ').map{it.toInt()}

    var answer = 1
    var d = Array<Int>(1010){0}
    d[0] = 1
    for(i in 1 until n)
    {
        var highest = 0
        for(j in 0 until i)
        {
            if(v[j] < v[i]) highest = Math.max(highest, d[j])
        }
        d[i] = highest + 1
        answer = Math.max(answer, d[i])
    }
    print(answer)
}