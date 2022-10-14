import java.io.BufferedReader
import java.io.InputStreamReader
import java.nio.Buffer
import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val a = sc.nextInt()
    val b = sc.nextInt()
    val c = sc.nextInt()
    val d = sc.nextInt()
    val e = sc.nextInt()

    val res1 = Math.min(a, Math.min(b, c))
    val res2 = Math.min(d, e)
    print(res1+res2-50)
}