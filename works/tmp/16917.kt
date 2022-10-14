import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var A = sc.nextInt()
    var B = sc.nextInt()
    var C = sc.nextInt()
    var X = sc.nextInt()
    var Y = sc.nextInt()
    var cost = 0

    while(true)
    {
        var x = 1
        var y = 1
        if(X <= 0) x = 0
        if(Y <= 0) y = 0

        var a = cost + A*x + B*y
        var b = cost + C * 2
        cost = Math.min(a, b)

        X--; Y--
        if(X < 0 && Y < 0) break
    }
    print(cost)
}