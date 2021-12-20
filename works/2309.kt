import java.util.*
import kotlin.collections.ArrayList

fun main()
{
    val sc = Scanner(System.`in`)
    var arr = Array<Int>(10){0}
    var sum = 0

    for(i in 0 until 9)
    {
        arr[i] = sc.nextInt();
        sum += arr[i];
    }
    sum -= 100

    var target1 = 0; var target2 = 0
    for(i in 0 until 9)
    {
        for(j in 0 until 9)
        {
            if(arr[i] + arr[j] == sum)
            {
                target1 = i; target2 = j;
                break;
            }
        }
    }

    var ans = ArrayList<Int>()
    for(i in 0 until 9)
    {
        if(i == target1 || i == target2) continue
        ans.add(arr[i])
    }
    ans.sort()

    for(x in ans) println(x)
}