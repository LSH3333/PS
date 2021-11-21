import java.util.*;

var d = Array(301) {0}
var a = Array(301) {0}

fun dp(n: Int): Int
{
    // base check
    if(n == 0) return a[0]
    else if(n == 1) return a[0] + a[1]
    else if(n == 2) return Math.max(a[0] + a[2], a[1] + a[2])

    // memoization
    if(d[n] > 0) return d[n]

    // recurrence relation
    d[n] = dp(n-2) + a[n]
    val v = dp(n-3) + a[n-1] + a[n]
    if(d[n] < v) d[n] = v

    return d[n]
}

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    for(i in 0..n-1) a[i] = sc.nextInt()

    print(dp(n-1))
}