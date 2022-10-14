import java.util.*


fun main()
{
    val sc = Scanner(System.`in`)
    val sb = StringBuilder()
    val dr = arrayOf(1, 0, -1, 0)
    val dc = arrayOf(0, 1, 0, -1)
    var N = sc.nextInt()
    var num = sc.nextInt()
    var cnt = N*N
    var r = 0; var c = 0; var dir = 0; var ansR = 0; var ansC = 0
    var v = Array(N) {Array(N) {0} }

    while(cnt > 0)
    {
        if(cnt == num) {ansR= r; ansC = c}
        v[r][c] = cnt
        var nr = r + dr[dir]
        var nc = c + dc[dir]

        if (nr < 0 || nr >= N || nc < 0 || nc >= N || v[nr][nc] != 0) {
            dir = (dir + 1) % 4
            nr = r + dr[dir]
            nc = c + dc[dir]
        }
        r = nr; c = nc
        cnt--
    }

    for (i in 0 until N) {
        for (j in 0 until N) {
            sb.append(v[i][j])
            sb.append(' ')
        }
        sb.append("\n")
    }
    sb.append(ansR + 1); sb.append(' '); sb.append(ansC+1)
    print(sb)
}