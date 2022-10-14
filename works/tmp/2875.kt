import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var N = sc.nextInt()
    var M = sc.nextInt()
    var K = sc.nextInt()

    var team = 0
    var n = 0
    var m = 0

    while(true)
    {
        n += 2; m += 1;
        if((N+M) - (n+m) < K) break;
        if(n > N || m > M) break;
        team++;
    }
    println(team)
}