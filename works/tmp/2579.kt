import java.util.*;


fun main(args: Array<String>)
{
    var d = Array<Array<Int>>(301) {Array(3){0} }
    var a = Array(301) {0}

    val sc = Scanner(System.`in`)
    val n = sc.nextInt();
    for(i in 0..n-1) a[i] = sc.nextInt()

    d[0][1] = a[0]
    d[1][1] = a[1]
    d[1][2] = a[0] + a[1]

    for(i in 2..n-1)
    {
        d[i][1] = Math.max(d[i-2][1], d[i-2][2]) + a[i]
        d[i][2] = d[i-1][1] + a[i]
    }
    print(Math.max(d[n-1][1], d[n-1][2]))
}