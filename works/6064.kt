import com.sun.org.apache.xpath.internal.functions.FuncFalse
import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var t = br.readLine().toInt()
    while(t-- > 0)
    {
        var _s = br.readLine().split(' ')
        var M = _s[0].toInt()
        var N = _s[1].toInt()
        var x = _s[2].toInt()
        var y = _s[3].toInt()

        var big = 0; var small = 0; var bigVal = 0; var smallVal = 0
        if(M < N) { big = N; bigVal = y; small = M; smallVal = x}
        else { big = M; bigVal = x; small = N; smallVal = y}

        var temp = smallVal
        var sub = big - small
        var cnt = 0
        var found = false

        while(true)
        {
            if(temp == bigVal) {found = true; break;}
            if(temp - sub <= 0)
            {
                var subTmp = temp - sub;
                temp = big - (subTmp * -1);
            }
            else temp -= sub;

            if(temp == smallVal) break;

            cnt++;
        }

        if(!found) println(-1)
        else println((small * cnt) + smallVal)
    }
}