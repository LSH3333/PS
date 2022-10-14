import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    var n = _s[0].toInt()
    var m = _s[1].toInt()
    _s = br.readLine().split(' ')
    var ans = 0; var ansSub = 99999999

    for(i in 0 until n)
    {
        for(j in i+1 until n)
        {
            for(k in j+1 until n)
            {
                var sum = _s[i].toInt() + _s[j].toInt() + _s[k].toInt()
                if(sum <= m && m-sum < ansSub)
                {
                    ansSub = m - sum
                    ans = sum
                }
            }
        }
    }
    print(ans)
}