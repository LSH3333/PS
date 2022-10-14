import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.pow

fun GetPos(n:Int):Int
{
    var len = 1
    var value = n
    var cnt = 0
    var num = 1

    while(value > 0)
    {
        if(value / 10 == 0)
        {
            cnt += (n - len + 1) * num
            break
        }
        else
        {
            cnt += 9 * len * num
            len *= 10
            num++
            value /= 10
        }
    }
    // 자릿수
    return cnt
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    var n = _s[0].toInt()
    var k = _s[1].toInt()
    if(n == 9 && k == 9) {print(9); return}
    val nPos = GetPos(n)
    if(k > nPos)
    {
        print(-1)
        return
    }

    var cnt = 0
    var num1 = 9L
    var num2 = 1L
    var res = 0L
    while(true)
    {
        if(res + num1 * num2 > k) break
        res += num1 * num2
        num1 *= 10
        num2++
        cnt++
    }
    cnt++
    var pos_d:Double
    if(cnt == 0) pos_d = 1.0
    else pos_d = Math.pow(10.0, (cnt-1).toDouble())
    var pos = pos_d.toInt()
    res++
    var num = pos

    while(true)
    {
        if(res > k) break
        num++
        res += cnt
    }

    num--
    res -= cnt
    var num_s = num.toString()
    var answer = num_s[k-res.toInt()]
    println(answer)

}