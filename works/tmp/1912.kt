import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var a = Array<Int>(100001){0}
    var d = Array<Int>(100001){0}
    var n = sc.nextInt()

    for(i in 0 until n)
    {
        val num = sc.nextInt()
        a[i] = num
    }

    d[0] = a[0]
    var answer = d[0]
    for(i in 1 until n)
    {
        d[i] = Math.max(d[i-1]+a[i], a[i])
        answer = Math.max(answer, d[i])
    }
    print(answer)
}