import java.util.*;

var w: Int = 0
var h: Int = 0
var dr = arrayOf(-1,-1,0,1,1,1,0,-1)
var dc = arrayOf(0,1,1,1,0,-1,-1,-1)
var arr = Array<Array<Int>>(0) {Array<Int>(0) {0}}
var mark = Array<Array<Boolean>>(0) {Array<Boolean>(0) {false}}

fun dfs(r: Int, c: Int)
{
    if(mark[r][c]) return
    mark[r][c] = true
    for(i in 0 until 8)
    {
        var nr = r + dr[i]
        var nc = c + dc[i]
        if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue
        if(arr[nr][nc] != 1) continue
        dfs(nr, nc)
    }
}

fun main(args: Array<String>)
{
    val sc = Scanner(System.`in`)

    while(true)
    {
        w = sc.nextInt()
        h = sc.nextInt()
        if(w == 0 && h == 0) return
        sc.nextLine()
        var ans = 0
        arr = Array<Array<Int>>(h) {Array<Int>(w) {0}}
        mark = Array<Array<Boolean>>(h) {Array<Boolean>(w) {false}}

        for(i in 0 until h)
        {
            for(j in 0 until w)
            {
                arr[i][j] = sc.nextInt()
            }
        }

        for(i in 0 until h)
        {
            for(j in 0 until w)
            {
                if(arr[i][j] != 1 || mark[i][j]) continue
                dfs(i, j)
                ans++
            }
        }
        println(ans)
    }

}