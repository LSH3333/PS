import java.util.*;

var A = 0
var P = 0

fun Cal(n: Int): Int {
    var sum = 0
    var _n = n
    while(_n > 0)
    {
        var res = Math.pow((_n%10).toDouble(), P.toDouble())
        sum += res.toInt()
        _n /= 10
    }
    return sum
}

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    var tmp = sc.nextLine()
    var s_tmp = tmp.split(" ")
    A = s_tmp[0].toInt()
    P = s_tmp[1].toInt()

    var m = HashMap<Int, Int>()
    var cnt = 1
    m.put(A, cnt++)

    while(true)
    {
        A = Cal(A)
        //println(A)
        if(m.containsKey(A))
        {
            var a = m.get(A)?.minus(1)
            print(a)
            break
        }
        m.put(A, cnt++)
    }
}