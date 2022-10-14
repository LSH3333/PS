import java.util.*
import kotlin.collections.HashMap

fun main()
{
    val sc = Scanner(System.`in`)
    val a = sc.nextInt()
    val b = sc.nextInt()
    var m = HashMap<Int, Int>()
    var num = a
    var cnt = 1

    while(true)
    {
        if(m[num] != null)
        {
            // !! : not null
            print(m.size - (m.get(num)!! - 1))
            break
        }
        m.put(num, cnt++)
        num = num * a % b
    }
}