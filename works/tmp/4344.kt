import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)

    var t = sc.nextInt()
    while(t-- > 0)
    {
        var n = sc.nextInt()
        var v = Array<Int>(n) {0}
        var avg = 0.0
        for(i in 0 until n)
        {
            var num = sc.nextInt()
            v[i] = num
            avg += num
        }
        avg /= n

        var over = 0.0
        for(i in 0 until n) if(v[i] > avg) over++

        var answer = over / n
        answer *= 100
        System.out.printf("%.3f%%\n", answer)

    }
}