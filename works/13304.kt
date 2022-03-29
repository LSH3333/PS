import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val N = sc.nextInt(); val K = sc.nextInt()
    var arr = Array(7) { Array(2) {0} }
    for(i in 0 until N)
    {
        val gender = sc.nextInt()
        val grade = sc.nextInt()
        arr[grade][gender]++
    }

    var v = Array(5) {0}
    v[0] = arr[1][0] + arr[1][1] + arr[2][0] + arr[2][1]
    v[1] = arr[3][0] + arr[4][0]
    v[2] = arr[3][1] + arr[4][1]
    v[3] = arr[5][0] + arr[6][0]
    v[4] = arr[5][1] + arr[6][1]

    var ans = 0
    for(x in v)
    {
        ans += x / K
        if(x % K != 0) ans++
    }
    print(ans)

}