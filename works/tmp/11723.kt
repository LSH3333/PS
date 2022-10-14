import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    var S = Array<Boolean>(21){false}
    var m = Integer.parseInt(br.readLine())

    while(m-- > 0)
    {
        val order = br.readLine()
        var op: String
        var num = 0

        var idx = order.indexOf(' ')
        if(idx != -1)
        {
            op = order.substring(0, idx)
            num = Integer.parseInt(order.substring(idx+1))
        }
        else
            op = order

        if(op.equals("add"))
        {
            S[num] = true;
        }
        else if(op.equals("remove"))
        {
            S[num] = false;
        }
        else if(op.equals("check"))
        {
            if(S[num]) bw.write("1\n");
            else bw.write("0\n");
        }
        else if(op.equals("toggle"))
        {
            S[num] = !S[num];
        }
        else if(op.equals("all"))
        {
            S = Array<Boolean>(21){true}
        }
        else if(op.equals("empty"))
        {
            S = Array<Boolean>(21){false}
        }
    }

    bw.flush();
    bw.close();
}

