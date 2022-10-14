import java.util.*

fun main()
{
    val arr = Array(1010) { BooleanArray(1010) {true} }
    arr[0][0] = false

    for(i in 0 .. 1000)
    {
        for(j in 0 .. 1000)
        {
            if(i == 0 && j == 0) continue
            if(!arr[i][j]) continue

            var a = i
            var b = j
            while(true)
            {
                a += i; b += j
                if(a > 1000 || b > 1000) break
                arr[a][b] = false
            }
        }
    }

    val answer = IntArray(1010) {0}
    var cnt = 0
    for(i in 0 .. 1000)
    {
        for(a in 0 until i)
        {
            if(arr[i][a]) cnt++
            if(arr[a][i]) cnt++
        }
        if(arr[i][i]) cnt++
        answer[i] = cnt
    }

    val sc = Scanner(System.`in`)
    var T = sc.nextInt()
    while(T-- > 0)
    {
        val N = sc.nextInt()
        println(answer[N])
    }

}
