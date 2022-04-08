import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val num = sc.next()
    var v = Array<Int>(num.length) {0}
    for(i in 0 until num.length) v[i] = num[i]-'0'
    Arrays.sort(v, Collections.reverseOrder())
    for(x in v) print(x)
}