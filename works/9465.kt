import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun main()
{
//    val br = BufferedReader(InputStreamReader(System.`in`))
//    var aaa = br.readLine().split(' ').map{it.toInt()}


    val sc = Scanner(System.`in`)
    val br = BufferedReader(InputStreamReader(System.`in`))

    var t = br.readLine().toInt()
    while(t-- > 0)
    {
        var n = br.readLine().toInt()
        var d = Array(3){Array(n+1){0} }
        var a = Array(2){Array(n+1){0} }

        for(i in 0 until 2)
        {
            var tmp = br.readLine().split(' ').map{it.toInt()}
            for(j in 0 until n)
            {
                a[i][j] = tmp[j]
            }
        }

        d[0][0] = a[0][0]
        d[1][0] = a[1][0]
        d[2][0] = Math.max(a[0][0], a[1][0])

        d[0][1] = a[0][1] + d[1][0]
        d[1][1] = a[1][1] + d[0][0]
        d[2][1] = Math.max(a[0][1], a[1][1])

        for(i in 2 until n)
        {
            // 위에 땜
            d[0][i] = a[0][i] + Math.max(d[1][i - 1], Math.max(d[0][i-2],Math.max(d[1][i-2],d[2][i-2])))
            // 아래 땜
            d[1][i] = a[1][i] + Math.max(d[0][i - 1], Math.max(d[0][i-2],Math.max(d[1][i-2],d[2][i-2])))
            // 이전을 안땠으므로 전전열 최댓값 + 현재 열 최댓값
            d[2][i] = Math.max(d[0][i - 2], Math.max(d[1][i - 2], d[2][i - 2])) + Math.max(a[0][i], a[1][i])
        }
        println(Math.max(d[0][n-1], Math.max(d[1][n-1], d[2][n-1])))
    }

}