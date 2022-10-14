import java.util.*

var d = Array(51) { Array(51) { Array(51) { 0 } } }

fun w(a:Int, b:Int, c:Int):Int
{
    if(a <= 0 || b <= 0 || c <= 0) return 1
    if(a > 20 || b > 20 || c > 20) return d[20][20][20]

    if(d[a][b][c] > 0) return d[a][b][c] // memoization
    if(a < b && b < c)
    {
        d[a][b][c-1] = w(a,b,c-1)
        d[a][b-1][c-1] = w(a,b-1,c-1)
        d[a][b-1][c] = w(a,b-1,c)
        return d[a][b][c-1] + d[a][b-1][c-1] - d[a][b-1][c]
    }

    d[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
    return d[a][b][c]
}

fun main()
{
    val sc = Scanner(System.`in`)
    d[0][0][0] = 1
    d[20][20][20] = 1048576

    while(true)
    {
        val a = sc.nextInt()
        val b = sc.nextInt()
        val c = sc.nextInt()
        if(a == -1 && b == -1 && c == -1) break

        val ans = w(a,b,c)
        var answer = "w("
        answer += Integer.toString(a)
        answer += ", "
        answer += Integer.toString(b)
        answer += ", "
        answer += Integer.toString(c)
        answer += ") = "
        answer += Integer.toString(ans) + '\n'
        print(answer)
    }
}