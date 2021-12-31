import java.io.*
import java.util.*

fun main()
{
    val sc = Scanner(System.`in`)
    val N = sc.nextInt()
    val M = sc.nextInt()

    if(N <= 1)
    {
        print(1)
        return
    }
    if(N <= 2)
    {
        if(M >= 9) print(4)
        else print((M-1)/2+1)
        return
    }

    if(M < 5)
    {
        print(M)
        return
    }
    if(M <= 5)
    {
        print(M-1)
        return
    }

    if(M > 5)
    {
        print(M-2)
    }
}

