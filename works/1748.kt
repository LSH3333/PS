import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var n = Integer.parseInt(br.readLine())
    var num = 1
    var cnt = 0
    while(num <= n)
    {
        cnt += (n - num + 1)
        num *= 10
    }
    print(cnt)
}