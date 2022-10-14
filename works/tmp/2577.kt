import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val a = sc.nextInt()
    val b = sc.nextInt()
    val c = sc.nextInt()
    val res = a * b * c
    val res_s = res.toString()
    var mark = Array(10) {0}
    for(i in 0 until res_s.length) mark[res_s[i]-'0']++
    for(i in 0 until 10) println(mark[i])

}