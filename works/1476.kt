import java.util.*
import kotlin.collections.ArrayList

fun main()
{
    val sc = Scanner(System.`in`)
    var E = sc.nextInt()
    var S = sc.nextInt()
    var M = sc.nextInt()

    var cnt = 1
    var e = 1; var s = 1; var m = 1
    while(true)
    {
        if(e == E && s == S && m == M) break;
        cnt++;

        if(e < 15) e++;
        else e = 1;

        if(s < 28) s++;
        else s = 1;

        if(m < 19) m++;
        else m = 1;
    }
    print(cnt)
}