import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    var arr = Array(15) { Array(15) {0} }
    for(i in 1 until 15) arr[0][i] = i
    for(i in 0 until 15) arr[i][1] = 1
    for(i in 1 until 15)
    {
        for(j in 1 until 15)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1]
        }
    }

    var t = sc.nextInt()
    while(t-- > 0)
    {
        var n = sc.nextInt(); var k = sc.nextInt()
        println(arr[n][k])
    }

}