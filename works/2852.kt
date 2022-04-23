import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Pair(var first: Int, var second: Int)
class Tuple(var x:Int, var y:Int, var z:Int)

fun ChangeToSec(time:String): Int
{
    var m = time.substring(0, 2)
    var s = time.substring(3)
    return m.toInt() * 60 + s.toInt()
}

fun ChangeToMin(time: Int): String
{
    val m = time / 60
    val s = time % 60
    var m_str = m.toString()
    var s_str = s.toString()
    if (m_str.length == 1) m_str = "0$m_str"
    if (s_str.length == 1) s_str = "0$s_str"
    return "$m_str:$s_str"
}

fun main()
{
    val sc = Scanner(System.`in`)
    val br = BufferedReader(InputStreamReader(System.`in`))

    var goal = ArrayList<Pair>()
    var N = br.readLine().toInt()
    for(i in 0 until N)
    {
        var _s = br.readLine().split(" ")
        val team = _s[0].toInt()
        val time = _s[1]
        goal.add(Pair(team, ChangeToSec(time)))
    }
    goal.add(Pair(0, 60*48))

    var t1 = 0
    var t2 = 0
    val v = ArrayList<Tuple>()
    for(i in 0 until N)
    {
        if(goal[i].first == 1) t1++ else t2++
        if(t1 == t2) continue
        val winning = if (t1 > t2) 1 else 2
        v.add(Tuple(goal[i].second, goal[i+1].second, winning))
    }

    var t1Time = 0
    var t2Time = 0
    for(tuple in v)
    {
        if(tuple.z == 1) t1Time += tuple.y - tuple.x
        else t2Time += tuple.y - tuple.x
    }

    println(ChangeToMin(t1Time))
    println(ChangeToMin(t2Time))
}