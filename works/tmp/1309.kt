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
    val MOD = 9901
    var d = Array(n+1){Array(3){0} }

    d[1][0] = 1
    d[1][1] = 1
    d[1][2] = 1

    for(i in 2..n)
    {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD
        d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD
        d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD
    }
    print((d[n][0] + d[n][1] + d[n][2]) % MOD)
}