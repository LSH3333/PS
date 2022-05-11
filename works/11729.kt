import java.util.*

class Pair(var first: Int, var second: Int)

var depth = 0
val l = ArrayList<Pair>()

fun Hanoi(num:Int, from:Int, by:Int, to:Int)
{
    depth++
    if(num == 1)
    {
        l.add(Pair(from, to))
        return
    }

    Hanoi(num-1, from, to, by)
    l.add(Pair(from, to))
    Hanoi(num-1, by, from, to)
}

fun main()
{
    val sc = Scanner(System.`in`)
    val sb = StringBuilder()

    val n = sc.nextInt()
    Hanoi(n, 1, 2, 3)
    println(depth)
    for(x in l)
    {
        sb.append(x.first).append(' ').append(x.second).append('\n')
    }
    print(sb)
}
