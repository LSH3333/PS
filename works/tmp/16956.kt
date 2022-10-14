import java.util.*;


fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)
    var R = sc.nextInt()
    var C = sc.nextInt()
    var arr = Array(501){CharArray(501){'a'}}
    sc.nextLine()

    for(i in 0 until R)
    {
        var r = sc.nextLine()
        for(j in 0 until C)
        {
            arr[i][j] = r[j]
        }
    }

    for(i in 0 until R)
    {
        for(j in 0 until C)
        {
            if(arr[i][j] != 'W') continue
            var flag = false

            if(i-1 >= 0)
                if(arr[i-1][j] == 'S') flag = true
            if(j+1 < C)
                if(arr[i][j+1] == 'S') flag = true
            if(i+1 < R)
                if(arr[i+1][j] == 'S') flag = true
            if(j-1 >= 0)
                if(arr[i][j-1] == 'S') flag = true

            if(flag)
            {
                print(0)
                return
            }
        }
    }

    println(1)
    for(i in 0 until R)
    {
        for(j in 0 until C)
        {
            if(arr[i][j] == '.') print('D')
            else print(arr[i][j])
        }
        println()
    }

}