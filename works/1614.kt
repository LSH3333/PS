import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var finger = br.readLine().toLong()
    var num = br.readLine().toLong()
    var ans = 0L
    var goAndReturn = 0L

    if(finger == 1L)
    {
        // 왕복할수 있는 횟수
        goAndReturn = num - 1;
        ans = 1 + (8 * goAndReturn);
        ans += 7;
    }
    else if(finger == 5L)
    {
        goAndReturn = num;
        ans = 1 + (8 * goAndReturn);
        ans += 3;
    }
    else
    {
        goAndReturn = num / 2;
        ans = 1 + (8 * goAndReturn);
        if(num % 2 == 0L)
        {
            ans += finger-2;
        }
        else
        {
            ans += 7 - finger + 1;
        }
    }
    print(ans)
}