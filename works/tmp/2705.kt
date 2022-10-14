import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var d = Array<Int>(1010){0}
    d[1] = 1
    d[2] = 2

    for(i in 1..1000)
    {
        var sum = 0
        for(j in 1..i/2) sum += d[j]
        d[i] = sum + 1
    }

    var t = sc.nextInt()
    while(t-- > 0)
    {
        var n = sc.nextInt()
        println(d[n])
    }
}