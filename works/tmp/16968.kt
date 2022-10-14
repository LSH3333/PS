import java.util.*
import kotlin.collections.ArrayList

fun main()
{
    val sc = Scanner(System.`in`)
    var str = sc.nextLine()
    var sum = 0
    if(str[0] == 'd') sum = 10
    else sum = 26

    for(i in 1 until str.length)
    {
        if(str[i] == str[i-1])
        {
            if(str[i] == 'd') sum *= 9
            else sum *= 25
        }
        else
        {
            if(str[i] == 'd') sum *= 10
            else sum *= 26
        }
    }
    print(sum)
}