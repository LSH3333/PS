import java.util.*

fun Draw(_r:Int, _c:Int, cnt:Int, depth:Int, stars:Array<CharArray>, N:Int)
{
    var r = _r
    var c = _c

    stars[r][c] = '*'
    for(i in 0 until cnt-1)
    {
        r--
        stars[r][c] = '*'
    }
    for(i in 0 until cnt-1)
    {
        c++
        if(c >= stars[r].size) break
        stars[r][c] = '*'
    }

    if(depth == N-1) return

    for(i in 0 until cnt+2-1)
    {
        r++
        stars[r][c] = '*'
    }
    for(i in 0 until cnt+2-1)
    {
        c--
        stars[r][c] = '*'
    }

    Draw(r, c, cnt+4, depth+1, stars, N)
}

fun Print(stars:Array<CharArray>)
{
    for(i in 0 until stars.size)
    {
        if(i == 1)
            println('*')
        else
        {
            for(j in 0 until stars[i].size)
                print(stars[i][j])
            println()
        }
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    val N = sc.nextInt()
    if(N==1)
    {
        print('*')
        return
    }

    val stars = Array(4*N-2+1) { CharArray(4*N-4+1) {' '} }

    Draw(2*N, 2*N-2, 3, 0, stars, N)

    Print(stars)
}
