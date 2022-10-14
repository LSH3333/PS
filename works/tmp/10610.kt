import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var n = sc.nextLine()

    var sum = 0
    var isZero = false
    for(i in 0 until n.length)
    {
        if(n[i] == '0') isZero = true
        sum += n[i]-'0'
    }

    if(sum % 3 == 0 && isZero)
    {
        val array = n.toCharArray()
        print(array.sortedDescending().joinToString(""))
    }
    else
        print(-1)
}