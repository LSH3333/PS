import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    var mark = Array<Boolean> (2000010) { false }
    var students = Array<Boolean> (2000010) { false }
    val n = sc.nextInt()
    val c = sc.nextInt()
    var cnt = 0

    for(i in 0 until n)
    {
        var num = sc.nextInt()
        if(students[num]) continue
        students[num] = true

        for(j in num .. c step num)
        {
            if(!mark[j])
            {
                cnt++
                mark[j] = true
            }
        }
    }
    print(cnt)
}