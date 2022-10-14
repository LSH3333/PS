import java.io.BufferedReader
import java.io.InputStreamReader
import java.nio.Buffer
import java.util.*


fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    var _s = br.readLine().split(' ')
    var v = ArrayList<Int>()
    v.add(_s[0].toInt())
    v.add(_s[1].toInt())
    v.add(_s[2].toInt())
    v.sort()
    print(v[1])
}