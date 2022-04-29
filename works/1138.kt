import sun.awt.image.BufferedImageDevice
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.sqrt

var N = 0
var fin = false

fun Permutation(line:IntArray, mark:BooleanArray, l:ArrayList<Int>, depth:Int, order:IntArray)
{
    if(fin) return

    if(depth == N)
    {
        var isAnswer = true
        for(i in 1 .. N)
        {
            var cur = l[i]
            var taller = order[cur]
            var cnt = 0
            for(j in 1 until i)
            {
                if(l[j] > l[i]) cnt++
            }
            if(cnt != taller) { isAnswer = false; break }
        }
        if(isAnswer)
        {
            for(i in 1 .. N) print("${l[i]} ")
            fin = true
        }
        return
    }

    for(i in 1 .. N)
    {
        if(mark[i]) continue
        mark[i] = true
        l.add(line[i])
        Permutation(line, mark, l, depth+1, order)
        mark[i] = false
        l.removeAt(l.size-1)
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()

    var line = IntArray(N+1)
    for(i in 1 .. N) line[i] = i

    var _s = br.readLine().split(' ')
    var order = IntArray(N+1)
    for(i in 1 .. N) order[i] = _s[i-1].toInt()

    var mark = BooleanArray(N+1)

    var l = ArrayList<Int>()
    l.add(0)
    Permutation(line, mark, l, 0, order)
}
