import java.io.BufferedReader
import java.io.InputStreamReader
import java.nio.Buffer
import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val N = sc.nextInt()
    val w = 4 * N - 3
    val h = 2 * N - 1
    var mid = w - N * 2
    var board = ArrayList<ArrayList<Char>>()

    //
    var a = ArrayList<Char>()
    for(i in 0 until N) a.add('*')
    for(i in 0 until mid) a.add(' ')
    for(i in 0 until N) a.add('*')
    board.add(a)
    mid-=2

    var l = 0
    for(i in 1 until N)
    {
        a = ArrayList<Char>()
        for(j in 0 until i) a.add(' ')
        a.add('*')
        for(j in 0 until N-2) a.add(' ')
        a.add('*')
        for(j in 0 until mid) a.add(' ')
        if(mid > 0) a.add('*')
        mid-=2
        for(j in 0 until N-2) a.add(' ')
        a.add('*')
        l = i-1
        board.add(a)
    }
    mid = 1

    for(i in N until h-1)
    {
        a = ArrayList<Char>()
        for(j in 0 until l) a.add(' ')
        l--
        a.add('*')
        for(j in 0 until N-2)  a.add(' ')
        a.add('*')
        for(j in 0 until mid) a.add(' ')
        mid += 2
        a.add('*')
        for(j in 0 until N-2) a.add(' ')
        a.add('*')
        board.add(a)
    }

    a = ArrayList<Char>()
    for(i in 0 until N) a.add('*')
    for(i in 0 until mid) a.add(' ')
    for(i in 0 until N) a.add('*')
    board.add(a)

    for(i in 0 until h)
    {
        for(x in board[i]) print(x)
        println()
    }

}