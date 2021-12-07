import java.util.*

var edge = Array<ArrayList<Int>>(0) {ArrayList<Int>(0)}
var answer = Array<Int>(0) { 0 }


fun bfs()
{
    var q = LinkedList<Int>()
    q.add(1)

    while(!q.isEmpty())
    {
        val v = q.poll()

        for(x in edge[v])
        {
            if(answer[x] != 0) continue;
            answer[x] = v
            q.add(x)
        }
    }
}


fun main()
{
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()

    edge = Array<ArrayList<Int>>(n+1) { ArrayList<Int>(0) }
    answer = Array<Int>(n+1){0}

    for(i in 0 until n-1)
    {
        val a = sc.nextInt()
        val b = sc.nextInt()
        edge[a].add(b)
        edge[b].add(a)
    }

    bfs()

    for(i in 2..n) println(answer[i])

}

