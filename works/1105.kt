import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    var n = _s[0]
    var m = _s[1]

    while(n.length != m.length)
        n = "0" + n

    var cnt = 0
    var _n = n
    var _m = m
    for(i in n.length-1 downTo  0)
    {
        if(n[i] == '8' && m[i] == '8')
        {
            n = n.substring(0,i) + '9' + n.substring(i+1)
            if(n.compareTo(m) > 0) cnt++
            else { n = _n; m = _m }
        }
    }
    print(cnt)
}